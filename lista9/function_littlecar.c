#include <stdio.h>
#include <stdlib.h>
#include "carrinho.h"

void CriarCarrinho(ListaProdutos *car){
    car->inicio = NULL;
    car->fim = NULL;
    car->tamanho = 0;
}

void RetornarTam(ListaProdutos *car){
    return (car->tamanho);
}

void CarrinhoVazio(ListaProdutos *car){
    if(car->fim == NULL){
        return 0;
    }
    return 1;
}

int AdicionarProduto(ListaProdutos *car, Produto produt){
    No *novo = (No *) malloc(sizeof(No));
    novo->prod = produt;
    novo->prox = NULL;
    if (CarrinhoVazio(car)){
        car->inicio = novo;
        car->fim = NULL;
        car->tamanho++;
        return 1;
    }
    No *auxp = car->inicio;
    N
}

void LerProdutos(Produto *prod){
    printf("Digite o nome do produto:\n");
    prod->nome[strcspn(prod->nome, "\n")] = '\0';
    printf("Digite a categoria do produto:\n");
    prod->categoria[strcspn(prod->categoria, "\n")] = '\0';
    printf("Digite o valor do produto:\n");
    scanf("%.2f", &prod->valor);
    printf("Digite a quantidade de itens:\n");
    scanf("%d", &prod->quantidade);
}

void MenuPrincipal(){
    printf("\n------Menu do Carrinho------\n");
    printf("1 - Adicionar Produto\n");
    printf("2 - Exibir Carrinho\n");
    printf("3 - Filtrar por categoria\n");
    printf("4 - Atualizar produto\n");
    printf("5 - Remover produto\n");
    printf("6 - Finalizar compra\n");
    printf("0 - Encerrar Programa\n");
    printf("Escolha: ");
}
