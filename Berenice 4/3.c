#include "header.h"

Produto produtoCad(Lista *lista) {

    Produto produto;

    unsigned long long int codigo;
    do {
        printf("Digite o Codigo do produto: ");
        scanf("%"PRIu64, &codigo);
        getchar();
        if(codigo < 1 || validarCodigo(codigo, lista)){
            printf("Codigo Invalido\n");
        }
    } while (codigo < 1 || validarCodigo(codigo, lista));

    produto.codigo = codigo;

    char nome[26];
    do {
        printf("Digite o nome do produto: ");
        fgets(nome, 25, stdin);
        getchar();
        if (!validarNome(nome)) {
            printf("Nome maior do que o permitido \n");
        }
    } while (!validarNome(nome));

    strcpy(produto.nomedoitem, nome);

    float valor;
    do {
        printf("Digite o valor do produto: ");
        scanf("%f", &valor);
        getchar();
        if (valor <= 0) {
            printf("O Estoque deve ser maior que 0\n");
        }
    } while (valor <= 0);

    produto.valor = valor;

    int estoque;
    do {
        printf("Digite a quantidade do item: ");
        scanf("%i", &estoque);
        getchar();
        if (estoque <= 0) {
            printf("O Estoque deve ser maior que 0\n");
        }
    } while (estoque < 0);

    produto.estoque = estoque;

    produto.quantidadevendida = 0;

    return produto;

}

int validarCodigo(unsigned long long int codigo, Lista* lista) {

    No *aux = lista->inicio;

    while (aux)
     {
        if (aux->produtos.codigo == codigo) {
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}

int validarNome(const char* nome) {

    size_t len = strlen(nome);

    if (len == 0 || len > 25) {
        return 0;
    }
    for (size_t i = 0; i < len; i++) {
        if (nome[i] != ' ') {
            return 1;
        }
    }
    return 0;
}
