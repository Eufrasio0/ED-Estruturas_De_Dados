#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automato.h"

int id = 1000;

void CriarPerc(ListaAuto *perc){
    perc->inicio = perc->fim = NULL;
    perc->tam = 0;
}

int Vazia(ListaAuto *perc){
    if(perc->inicio == NULL){
        return 1;
    }
    return 0;
}

void PreencherPerc(TipoTrecho *t) {
    printf("\nDigite a direcao (um caractere): ");
    getchar();
    t->direcao = getchar();
    t->idTrecho = id;
    id++;
    printf("\nDigite a distancia em metros: ");
    scanf("%f", &t->distancia);
}


int InserirPerc(ListaAuto *perc, TipoTrecho t){
    No *tre = (No *)malloc(sizeof(No));
    tre->dado = t;
    tre->ant = tre->prox = NULL;
    if (Vazia(perc)) {
        perc->inicio = perc->fim = tre;
    } else {
        perc->fim->prox = tre;
        tre->ant = perc->fim;
        perc->fim = tre;
    }
    perc->tam++;
    return 1;
}

int InserirPercPos(ListaAuto *perc, TipoTrecho t, int pos){
    if (pos < 0 || pos > perc->tam){
        printf("\nPosicao invalida");
        return 0;
    }
    if (Vazia(perc) || pos == 0){
        No *novo = (No*) malloc(sizeof(No));
        novo->dado = t;
        novo->ant = NULL;
        novo->prox = perc->inicio;
        if (!Vazia(perc)){
            perc->inicio->ant = novo;
        }
        else{
            perc->fim = novo;
        }
        perc->inicio = novo;
        perc->tam++;
        return 1;
    }
    if (pos == perc->tam){
        return InserirPerc(perc, t);
    }
    No *aux = perc->inicio;
    for (int i = 0; i < pos - 1; i++){
        aux = aux->prox;
    }
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = t;
    novo->prox = aux->prox;
    novo->ant = aux;
    aux->prox->ant = novo;
    aux->prox = novo;
    perc->tam++;
    return 1;
}


float DistanciaTotal(ListaAuto *l){
    float t = 0.0;
    No *aux = l->inicio;
    while (aux != NULL) {
        t += aux->dado.distancia;
        aux = aux->prox;
    }
    return t;
}


void ExibirPercTotal(ListaAuto *perc){
    No *aux = perc->inicio;
    if(Vazia(perc)){
        printf("\nLista Vazia, Defina um percurso ao automato");
        return;
    }
    while(aux!=NULL){
        printf("\nDirecao = %c", aux->dado.direcao);
        printf("\nId do trecho = %d", aux->dado.idTrecho);
        printf("\nDistancia = %.2f metros", aux->dado.distancia);
        printf("\n");
        aux = aux->prox;
    }
    printf("\nFIM DO PERCURSO");
    return;
}
void RemoverPosPerc(ListaAuto *perc, int pos){
    if(pos < 0 || pos >= perc->tam){
        printf("\nPosicao invalida");
        return;
    }
    No *aux = perc->inicio;
    if(perc->tam == 1){
        free(aux);
        perc->inicio = perc->fim = NULL;
        perc->tam = 0;
        printf("\nTRECHO REMOVIDO");
        return;
    }

    if(pos == 0){
        perc->inicio = aux->prox;
        perc->inicio->ant = NULL;
        free(aux);
        perc->tam--;
        printf("\nTRECHO REMOVIDO");
        return;
    }
    if(pos == perc->tam - 1){
        aux = perc->fim;
        perc->fim = aux->ant;
        perc->fim->prox = NULL;
        free(aux);
        perc->tam--;
        printf("\nTRECHO REMOVIDO");
        return;
    }
    for(int i = 0; i < pos; i++){
        aux = aux->prox;
    }
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
    printf("\nTRECHO REMOVIDO");
    perc->tam--;
}

void MenuPrinc(){
    printf("\n----Menu-----\n");
    printf("\n1 - Adicionar Percurso");
    printf("\n2 - Exibir distancia total");
    printf("\n3 - Exibir percurso");
    printf("\n4 - Remover por posicao");
    printf("\n5 - Inserir por posicao");
    printf("\n0 - Encerrar Programa");
    printf("\nEscolha: ");
}
