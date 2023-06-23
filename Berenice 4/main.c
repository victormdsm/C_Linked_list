#include "header.h"

int main () {

    int opcao;
    Lista lista;
    inicializaLista(&lista);

    do {

        imprimeMenu();
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);
        getchar();
        system("cls");

        switch (opcao){

            case 1:
                printf("Opcao selecionada: Produtos\n");
                system("pause");
                subMenu(&lista);
                break;
            case 2:
                printf("Opcao selecionada: Vendas\n");
                system("pause");
                vendas(&lista);
                break;
            case 3:
                printf("Opcao selecionada: Sair\n");
                printf("Muito Obrigado por usar o nosso sistema !\n");
                break;
            default:
                printf("Opcao escolhida invalida tente novamente\n");
                system("pause");
                break;
        }


    }while(opcao != 3);

    //desaloca a memoria
    limparLista(&lista);

    return 0;

}
