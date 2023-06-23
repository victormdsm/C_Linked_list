#include "header.h"

void inserirOrdenado(Lista2* lista2, Vendidos novaVenda) {
    No2* novoNo = (No2*)malloc(sizeof(No2));
    novoNo->vendas = novaVenda;
    novoNo->proximo = NULL;

    if (lista2->inicio == NULL || novaVenda.ValorTotal >= lista2->inicio->vendas.ValorTotal) {
        novoNo->proximo = lista2->inicio;
        lista2->inicio = novoNo;
    } else {
        No2* atual2 = lista2->inicio;
        while (atual2->proximo != NULL && novaVenda.ValorTotal < atual2->proximo->vendas.ValorTotal) {
            atual2 = atual2->proximo;
        }
        novoNo->proximo = atual2->proximo;
        atual2->proximo = novoNo;
    }
}

void desalocarLista2(Lista2* lista2) {
    No2* atual = lista2->inicio;
    while (atual != NULL) {
        No2* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista2->inicio = NULL;
}

float acrescimoCompra(float valorTotal, int parcelas)
{
    float acrescimo;
    if (parcelas <= 3)
    {
        acrescimo = valorTotal * 1.05;
    }
    else
    {
        acrescimo = valorTotal * 1.08;
    }
    return acrescimo;
}
