#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct {
    unsigned long long int codigo;
    char nomedoitem[25];
    float valor;
    int estoque;
    int quantidadevendida;
}Produto;

typedef struct
{
    unsigned long long int codigo;
    char nomedoitem[25];
    float valorUnitario;
    int quantidadeVendida;
    float ValorTotal;
}Vendidos;

typedef struct no {
   Produto produtos;
   struct no *proximo;
   struct no *anterior;
}No;

typedef struct no2 {
    Vendidos vendas;
    struct no2 *proximo;
}No2;

typedef struct lista {
   No *inicio;
}Lista;

typedef struct lista2 {
   No2 *inicio;
}Lista2;



//arquivo 1.c
void inicializaLista(Lista *);
void imprimeMenu(void);
void imprimeSubMenu();
//arquivo 2.c
void subMenu(Lista*);
void exibir(Lista);
void cadastrar(Lista*);
//arquivo 3.c
Produto produtoCad(Lista *);
void atualizar(Lista*);
void excluirProduto(Lista*);
//arquivo 4.c
No* buscarProdutoCodigo(Lista *lista, unsigned long long);
void salvarProdutos(Lista *);
void lerProdutos(Lista*);
//arquivo 5.c
void adicionarNo(Lista*, Produto);
void limparLista(Lista*);
void vendas(Lista*);
//arquivo 6.c
void realizaVenda(Lista*);
void inserirOrdenado(Lista2*, Vendidos);
void desalocarLista2(Lista2* );
//arquivo 7.c
void relatorioVendas(Lista);
int validarCodigo(unsigned long long int , Lista* );
int validarNome(const char*);
//arquivo 8.c
float acrescimoCompra(float, int);
float descontoCompra(float );
void pagamento(float);


#endif // HEADER_H_INCLUDED
