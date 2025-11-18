#ifndef AUTOMATO_H_INCLUDED
#define AUTOMATO_H_INCLUDED

typedef struct trecho{
 int idTrecho;
 char direcao;
 float distancia;
} TipoTrecho;

typedef struct no {
  TipoTrecho dado;
  struct no *prox;
  struct no *ant;
} No;

typedef struct Lista {
    No *inicio;
    No *fim;
    int tam;
}ListaAuto;

void PreencherPerc(TipoTrecho *t);
void CriarPerc(ListaAuto *perc);
float DistanciaTotal(ListaAuto *perc);
void ExibirPercTotal(ListaAuto *perc);
int InserirPerc(ListaAuto *perc, TipoTrecho t);
void MenuPrinc(void);
void PreencherPerc(TipoTrecho *t);
void RemoverPosPerc(ListaAuto *perc, int pos);
int Vazia(ListaAuto *perc);
int InserirPercPos(ListaAuto *perc, TipoTrecho t, int pos);

#endif // AUTOMATO_H_INCLUDED
