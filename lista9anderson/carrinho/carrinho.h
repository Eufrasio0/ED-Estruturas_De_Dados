#ifndef CARRINHO_H
#define CARRINHO_H

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
int CarrinhoVazio(ListaProdutos *car);
int RetornarTam(ListaProdutos *car);
int AdicionarProduto(ListaProdutos *car, Produto produt);
void RemoverProduto(ListaProdutos *carrinho, char nome[]);
void AtualizarProd(ListaProdutos *carrinho, char nome[]);
float finalizarCarrinho(ListaProdutos *carrinho);
void ExibirCarrinho(ListaProdutos *car);
void FiltrarCategoria(ListaProdutos *carrinho, char cate[]);
void LerProdutos(Produto *prod);
void LerCategoria(char categoria[]);
void LerNome(char nome[]);
void MenuPrincipal(void);

#endif // CARRINHO_H_INCLUDED
