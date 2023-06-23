#include "header.h"

void limparLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
}

void vendas(Lista *lista) {

    int opcao;


    do {

        printf("\n==========  VENDAS  ==========\n");
        printf("1. Realizar venda\n");
        printf("2. Relatorio de vendas\n");
        printf("3. Voltar\n");
        printf("===============================\n");


        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("a opcao escolhida foi: Realizar Venda\n");
            system("pause");
            system("cls");
            realizaVenda(lista);
            break;
        case 2:
            printf("A opcao escolhida foi: Relatorio de Vendas");
            system("pause");
            system("cls");
            relatorioVendas((*lista));
            break;
        case 3:
            printf("Voltandooooo\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("opcao invalida");
            break;
        }

    }while(opcao != 3);


}

void realizaVenda(Lista* lista) {
    No* venda;
    Lista2 lista2;
    lista2.inicio = NULL;
    unsigned long long int codigo;

    int quant;
    int repete;
    int x = 0;
    float valorTotal = 0;

    if (lista->inicio != NULL) {


        do {
            exibir((*lista));
            float valor_compra = 0;
            printf("Digite o codigo do produto que voce deseja vender: \n");
            scanf("%" PRIu64, &codigo);

            venda = buscarProdutoCodigo(lista, codigo);

            if (venda != NULL) {
                x = 1;
                do {
                    printf("Digite a quantidade que voce deseja vender: ");
                    scanf("%i", &quant);
                    if (quant > venda->produtos.estoque || quant <= 0) {
                        printf("Digite uma quantidade valida\n");
                    }
                } while (quant > venda->produtos.estoque || quant <= 0);

                venda->produtos.estoque -= quant;
                venda->produtos.quantidadevendida += quant;
                valor_compra = venda->produtos.valor * quant;
                valorTotal += venda->produtos.valor * quant;

                Vendidos novaVenda;
                novaVenda.codigo = venda->produtos.codigo;
                strcpy(novaVenda.nomedoitem, venda->produtos.nomedoitem);
                novaVenda.valorUnitario = venda->produtos.valor;
                novaVenda.quantidadeVendida = quant;
                novaVenda.ValorTotal = valor_compra;

                inserirOrdenado(&lista2, novaVenda);

            }

            if (x == 1) {
                do {
                    printf("Deseja realizar mais uma venda? 1 para sim ou 2 para nao: \n");
                    scanf("%i", &repete);
                    if (repete < 1 || repete > 2) {
                        printf("Opcao invalida\n");
                    }
                } while (repete < 1 || repete > 2);
            } else {
                printf("Produto nao encontrado!\n");
            }
        } while (repete != 2);

        No2 *nota = lista2.inicio;
        printf("Codigo do Item\tItem\t\tValor Unitario\tQuantidade\tPreco\n");
        while (nota) {
            printf("%-15" PRIu64 "%-20s%-15.2f%-15iR$ %.2f\n", nota->vendas.codigo, nota->vendas.nomedoitem, nota->vendas.valorUnitario, nota->vendas.quantidadeVendida, nota->vendas.ValorTotal);
            nota = nota->proximo;
        }
        printf("\t\t\t\tValor total:\tR$ %.2f\n", valorTotal);

        pagamento(valorTotal);

        desalocarLista2(&lista2);

    } else {
        printf("Nenhum produto cadastrado, não e possivel realizar a venda!\n");
    }
}
