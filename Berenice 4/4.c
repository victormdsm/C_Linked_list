#include "header.h"

void atualizar(Lista *lista) {

    No *troca = lista->inicio;
    unsigned long long cod_troca;
    float valorAntigo;
    int estoqueAntigo;


    exibir((*lista));

    printf("Digite o Codigo do produto que voce deseja alterar: ");
    scanf("%"PRIu64, &cod_troca);

    while (troca) {

        if (troca->produtos.codigo == cod_troca) {


            float valor;
            do {
                printf("Digite o valor do produto: ");
                scanf("%f", &valor);
                getchar();
                if (valor <= 0) {
                    printf("O Estoque deve ser maior que 0\n");
                }
            } while (valor <= 0);
            valorAntigo = troca->produtos.valor;
            troca->produtos.valor = valor;

            int estoque;
            do {
                printf("Digite a quantidade do item: ");
                scanf("%i", &estoque);
                getchar();
                if (estoque <= 0) {
                    printf("O Estoque deve ser maior que 0\n");
                }

            } while (estoque <= 0);
            estoqueAntigo = troca->produtos.estoque;
            troca->produtos.estoque = estoque;


            system("cls");
            printf("\nAntigo Cadastro:\n");
            printf("%-12s %-25s %-10s %s\n", "Codigo", "Nome do Item", "Valor", "Estoque");
            printf("%-13" PRIu64 " %-25s R$ %.2f %d\n", troca->produtos.codigo, troca->produtos.nomedoitem, valorAntigo, estoqueAntigo);

            printf("\nNovo Cadastro:\n");
            printf("%-13s %-25s %-10s %s\n", "Codigo", "Nome do Item", "Valor", "Estoque");
            printf("%-13"PRIu64 "%-25s R$ %.2f %d\n", troca->produtos.codigo, troca->produtos.nomedoitem, troca->produtos.valor, troca->produtos.estoque);

            system("pause");
            break;
        }
        troca = troca->proximo;
        if(troca == NULL) {
            printf("Produto não encontrado");
        }
    }


}

void excluirProduto(Lista* lista) {

    No *remover = NULL;
    unsigned long long int cdg_excluir;
    int confirmacao;

    system("cls");

    exibir((*lista));

    printf("Digite o codigo do produto que voce deseja excluir? ");
    scanf("%" PRIu64, &cdg_excluir);
    remover = buscarProdutoCodigo(lista, cdg_excluir);
    if (remover) {

        do {
            printf("Deseja Realmente excluir o produto ?\n digite 1 para sim e 2 para nao: ");
            scanf("%i", &confirmacao);

            switch (confirmacao)
            {
            case 1:
                if(remover->anterior == NULL){
                    lista->inicio = remover->proximo;
                }else{
                    remover->anterior->proximo = remover->proximo;
                }

                if(remover->proximo != NULL){
                    remover->proximo->anterior = remover->anterior;
                }
                break;
                free(remover);
            case 2:
                printf("Exclusão cancelada");
                break;
            default:
                printf("Opção invalida");
                break;
            }
        } while (confirmacao > 2 || confirmacao < 1);

    } else {
        printf("Produto não encontrado");
    }
}

No* buscarProdutoCodigo(Lista *lista, unsigned long long cdg) {

   No *aux;
   aux = lista->inicio;

   while (aux != NULL && aux->produtos.codigo != cdg) {
     aux = aux->proximo;
  }
   return aux;
}
