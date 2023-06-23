#include "header.h"

float descontoCompra(float valorTotal)
{
    float desconto;
    if (valorTotal <= 50)
    {
        desconto = valorTotal * 0.95;
    }
    else if (valorTotal > 50 && valorTotal < 100)
    {
        desconto = valorTotal * 0.90;
    }
    else
    {
        desconto = valorTotal * 0.82;
    }
    return desconto;
}

void pagamento(float valorTotal) {

    int pagamento, troco, parcelas = 1;
    float valorCompra, dinheiro = 0.00, devolucao;

    do
    {

        printf("Qual a forma de pagamento desejada (1 para a vista) (2 para a prazo) : \n");
        scanf("%i", &pagamento);

        switch (pagamento)
        {
        case 1:
            printf("Opcao selecionada a vista\n");
            valorCompra = descontoCompra(valorTotal);
            printf("o valor com desconto e de: %.2f\n", valorCompra);
            // laço para verificar se precisa de troco ou nao
            do
            {

                printf("Precisa de troco ? (1) para sim e (2) para nao: \n");
                scanf("%i", &troco);

                switch (troco)
                {

                case 1:
                    while (dinheiro < valorCompra)
                    {

                        printf("Digite o valor pago pelo cliente:\n ");
                        scanf("%f", &dinheiro);

                        if (dinheiro < valorCompra)
                        {
                            printf("Pagamento Invalido\n");
                        }
                    }
                    devolucao = dinheiro - valorCompra;
                    printf("O troco e de: %.2f\n", devolucao);
                    printf("Muito Obrigado pela preferencia\n");
                    break;
                case 2:
                    printf("Muito Obrigado pela preferencia\n");
                    break;
                default:
                    printf("Selecao Invalida\n");
                    break;
                }
            } while (troco < 1 && troco > 2);
            break;

        case 2:
            printf("Opcao selecionada a prazo\n");
            printf("O Valor da compra é de: %.2f\n", valorTotal);
            while (parcelas < 2)
            {
                printf("Digite a quantidade de parcelas: \n");
                scanf("%i", &parcelas);
                if (parcelas < 2)
                {
                    printf("Numero de parcelas invalidas\n");
                }
                else
                {
                    valorCompra = acrescimoCompra(valorTotal, parcelas);
                    printf("O valor com acrescimo e de: R$%.2f\n", valorCompra);
                    printf("%i X de: R$%.2f\n", parcelas, (valorCompra / parcelas));
                }
            }
            break;

        default:
            printf("Opcao de pagamento invalida\n");
            break;
        }

    } while (pagamento < 1  || pagamento > 2);

    system("pause");
    system("cls");


}

void relatorioVendas(Lista lista) {
        No *aux = lista.inicio;

        if(aux) {

        printf("Codigo do Item\tItem\t\t\tValor\t\tEstoque\tQuantidade Vendida\n");
        while (aux) {
            printf("%-15"PRIu64"%-30sR$ %.2f\t%i\t%i\n", aux->produtos.codigo,  aux->produtos.nomedoitem,  aux->produtos.valor,  aux->produtos.estoque,  aux->produtos.quantidadevendida);
            aux = aux->proximo;
        }
    } else {
        printf("Nenhum produto cadastrado\n");
    }

    system("pause");
    system("cls");

}
