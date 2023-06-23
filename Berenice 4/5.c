#include "header.h"

void salvarProdutos(Lista* lista) {

    FILE* fp;
    fp = fopen("produtos.txt", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    No *save = lista->inicio;
    if(save) {

        while (save) {
            fwrite(&(save->produtos), sizeof(Produto), 1, fp);
            save = save->proximo;
        }

        printf("Produtos salvos com sucesso no arquivo produtos.txt.\n");
        system("pause");
        system("cls");


    } else {
        printf("Nenhum produto cadastrado ainda");


    }
    fclose(fp);
}

void adicionarNo(Lista* lista, Produto novoProduto) {

    No* novo = (No*)malloc(sizeof(No));
    novo->produtos = novoProduto;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
        novo->anterior = atual;
    }
}

void lerProdutos(Lista* lista) {
    FILE* arquivo = fopen("produtos.txt", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    limparLista(lista);

    Produto produto;
    while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
        adicionarNo(lista,produto);
    }
    printf("Produto Lido com sucesso\n");
    system("pause");


    fclose(arquivo);
}
