#include <stdio.h>
#include <stdlib.h>
#include "carrinho.h"

int main(){
    ListaProdutos carrinho;
    CriarCarrinho(&carrinho);
    int opcao;
    do {
        MenuPrincipal();
        scanf("%d", &opcao);
        getchar();
            switch(opcao){

        case 1:


        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        case 0:

        default:
            printf("OPCAO INVALIDA");
            }
    } while (opcao != 0);
    return 0;
}

