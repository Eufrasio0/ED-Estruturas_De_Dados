#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int main(){
    int pos, opcao = -1;
    TipoTrecho tre;
    ListaAuto perc;
    CriarPerc(&perc);
    float dist = 0;
    while(opcao != 0){
        MenuPrinc();
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            PreencherPerc(&tre);
            InserirPerc(&perc, tre);
            break;

        case 2:
            dist = DistanciaTotal(&perc);
            printf("\nDistancia total: %.2f metros\n", dist);
            break;

        case 3:
            ExibirPercTotal(&perc);
            break;
        case 4:
            printf("\nDigite a posicao do percurso: ");
            scanf("%d", &pos);
            RemoverPosPerc(&perc, pos);
            break;
        case 5:
            PreencherPerc(&tre);
            printf("\nDigite a posicao que deseja inserir o percurso: ");
            scanf("%d", &pos);
            InserirPercPos(&perc, tre, pos);
            break;
        case 0:
            printf("\nFIM DO PROGRAMA");
            break;
        default:
            printf("\nOPCAO INVALIDA");
            break;
        }
    }
    return 0;
}
