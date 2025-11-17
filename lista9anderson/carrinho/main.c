#include <stdio.h>
#include <stdlib.h>
#include "carrinho.h"

int main(){
    ListaProdutos carrinho;
    CriarCarrinho(&carrinho);
    int opcao;
    char cate[15], nome[20];
    Produto prod;
    do {
        MenuPrincipal();
        scanf("%d", &opcao);
        getchar();
            switch(opcao){

       case 1:
            LerProdutos(&prod);
            AdicionarProduto(&carrinho, prod);
            break;
        case 2:
            ExibirCarrinho(&carrinho);
            break;

        case 3:
            LerCategoria(cate);
            FiltrarCategoria(&carrinho, cate);
            break;

        case 4:
            LerNome(nome);
            AtualizarProd(&carrinho, nome);
            break;

        case 5:
            LerNome(nome);
            RemoverProduto(&carrinho, nome);
            break;

        case 6:
            finalizarCarrinho(&carrinho);
            break;

        default:
            printf("OPCAO INVALIDA");
            break;

            }
    } while (opcao != 0);
    return 0;
}
