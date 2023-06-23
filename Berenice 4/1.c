#include "header.h"

void inicializaLista(Lista *lista) {
   lista->inicio = NULL;
}

void imprimeMenu() {

    printf("\n========== MENU ==========\n");
    printf("1. Produtos\n");
    printf("2. Vendas\n");
    printf("3. Sair\n");
    printf("==========================\n");

}

void imprimeSubMenu() {
    printf("\n========== SUBMENU ==========\n");
    printf("1. Exibir\n");
    printf("2. Cadastrar\n");
    printf("3. Atualizar\n");
    printf("4. Excluir\n");
    printf("5. Salvar\n");
    printf("6. Ler\n");
    printf("7. Voltar\n");
    printf("=============================\n");
}
