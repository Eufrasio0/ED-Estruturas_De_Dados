#ifndef CARRINHO_H_INCLUDED
#define CARRINHO_H_INCLUDED

typedef struct produto {
     char nome[20];
     char categoria[15];
     int quantidade;
     float valor;
} Produto;

typedef struct no {
     Produto prod;
     struct no *ant;
     struct no *prox;
} No;

typedef struct lista {
     No *inicio;
     No *fim;
     int tamanho;
} ListaProdutos;

void CriarCarrinho(ListaProdutos *car);
void RetornarTam(ListaProdutos *car);
void CarrinhoVazio(ListaProdutos *car);

#endif // CARRINHO_H_INCLUDED
