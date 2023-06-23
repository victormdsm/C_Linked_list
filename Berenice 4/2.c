#include "header.h"

void subMenu(Lista *lista) {

    int opcao;


    do {

        imprimeSubMenu();

        printf("Digite o valor desejado: ");
        scanf("%i", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                printf("\nOpcao selecionada: Exibir\n");
                exibir((*lista));
                system("pause");
                system("cls");
                break;

            case 2:
                printf("\nOpcao selecionada: Cadastrar\n");
                cadastrar(lista);
                break;

            case 3:
                printf("\nOpcao selecionada: Atualizar\n");
                atualizar(lista);
                break;

            case 4:
                printf("\nOpcao selecionada: Excluir\n");
                excluirProduto(lista);
                break;

            case 5:
                printf("\nOpcao selecionada: Salvar\n");
                system("cls");
                salvarProdutos(lista);
                break;

            case 6:
                printf("\nOpcao selecionada: Ler\n");
                lerProdutos(lista);
                system("cls");
                break;

            case 7:
                printf("\nOpcao selecionada: Voltar\n");
                system("pause");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 7);
}

void exibir(Lista lista) {
    No *no = lista.inicio;

    if(lista.inicio != NULL) {

    printf("Codigo do Item\tItem\t\t\tValor\t\tEstoque\n");
    //acertar a formatação
    while (no)
    {
        printf("%-15" PRIu64 "%-30sR$ %10.2f\t%5i\n", no->produtos.codigo, no->produtos.nomedoitem, no->produtos.valor, no->produtos.estoque);
        no = no->proximo;
    }
    } else {
        printf("Nenhum produto cadastrado\n");
    }

}

void cadastrar(Lista *lista) {

    int qtd_cad, i = 0 ;
    do{
        printf("Digite a quantidade de itens que voce quer cadastrar: ");
        scanf("%i", &qtd_cad);
        getchar();
    } while (qtd_cad<1);

    while (i < qtd_cad) {
        No *novo = (No*) malloc(sizeof(No));
        Produto produto = produtoCad(lista);
        if(novo) {
            novo->produtos = produto;
            novo->proximo = lista->inicio;
            novo->anterior = NULL;

            if(lista->inicio) {
                lista->inicio->anterior = novo;
            }

            lista->inicio = novo;
        }
        if(novo == NULL) {
            printf("Erro ao alocar memoria");
        }
        i++;
    }


}
