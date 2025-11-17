#include <stdio.h>
#include <stdlib.h>
#include "carrinho.h"
#include <string.h>

void CriarCarrinho(ListaProdutos *car){
    car->inicio = NULL;
    car->fim = NULL;
    car->tamanho = 0;
}

int RetornarTam(ListaProdutos *car){
    return car->tamanho;
}

int CarrinhoVazio(ListaProdutos *car){
    if(car->inicio == NULL && car->fim == NULL){
        return 1;
    }
    return 0;
}

int AdicionarProduto(ListaProdutos *car, Produto produt){
    No *novo = (No *) malloc(sizeof(No));
    novo->prod = produt;
    novo->prox = NULL;
    novo->ant = NULL;
    if(CarrinhoVazio(car)){
        car->inicio = novo;
        car->fim = novo;
    } else {
        novo->ant = car->fim;
        car->fim->prox = novo;
        car->fim = novo;
    }
    car->tamanho++;
    return 1;
}
void ExibirCarrinho(ListaProdutos *car) {
    float total = 0;
    if (car->inicio == NULL) {
        printf("\nO carrinho vazio!\n");
        return;
    }
    No *aux = car->inicio;
    printf("\n----- ITENS NO CARRINHO ----\n");
    while (aux != NULL) {
        printf("\nNome: %s", aux->prod.nome);
        printf("\nCategoria: %s", aux->prod.categoria);
        printf("\nValor: R$ %.2f", aux->prod.valor);
        printf("\nQuantidade: %d\n", aux->prod.quantidade);
        printf("-------------------------------\n");
        total += aux->prod.valor * aux->prod.quantidade;
        aux = aux->prox;
    }
    printf("Total de produtos no carrinho: %d\n", car->tamanho);
    printf("Total do carrinho: %.2f\n", total);
}


void LerProdutos(Produto *prod){
    printf("Digite o nome do produto: ");
    fgets(prod->nome, sizeof(prod->nome), stdin);
    prod->nome[strcspn(prod->nome, "\n")] = '\0';
    printf("\nDigite a categoria do produto: ");
    fgets(prod->categoria, sizeof(prod->categoria), stdin);
    prod->categoria[strcspn(prod->categoria, "\n")] = '\0';
    printf("\nDigite o valor do produto: ");
    scanf("%f", &prod->valor);
    printf("\nDigite a quantidade de itens: ");
    scanf("%d", &prod->quantidade);
}

void LerCategoria(char categoria[]) {
    printf("Digite a categoria: ");
    fgets(categoria, 15, stdin);
    categoria[strcspn(categoria, "\n")] = '\0';
}

void LerNome(char nome[]) {
    printf("Digite o nome do produto que deseja atualizar: ");
    fgets(nome, 20, stdin);
    nome[strcspn(nome, "\n")] = '\0';
}

void FiltrarCategoria(ListaProdutos *carrinho, char cate[]) {
    No *aux = carrinho->inicio;
    int cont = 0;
    while (aux != NULL) {
        if (strcmp(aux->prod.categoria, cate) == 0) {
            printf("\nNome: %s", aux->prod.nome);
            printf("\nCategoria: %s", aux->prod.categoria);
            printf("\nValor: R$ %.2f", aux->prod.valor);
            printf("\nQuantidade: %d\n", aux->prod.quantidade);
            printf("-------------------------------\n");
            cont++;
        }
        aux = aux->prox;
    }
    if (cont == 0) {
        printf("\nNenhum produto encontrado na categoria '%s'.\n", cate);
    }
}

void AtualizarProd(ListaProdutos *carrinho, char nome[]){
    No *aux = carrinho->inicio;
    while(aux != NULL){
        if(strcmp(aux->prod.nome, nome) == 0){
            printf("\nDigite a nova categoria do produto: ");
            fgets(aux->prod.categoria, sizeof(aux->prod.categoria), stdin);
            aux->prod.categoria[strcspn(aux->prod.categoria, "\n")] = '\0';
            printf("\nDigite o novo valor do produto: ");
            scanf("%f", &aux->prod.valor);
            printf("\nDigite a nova quantidade de itens: ");
            scanf("%d", &aux->prod.quantidade);
            return;
        }
        aux = aux->prox;
    }
    printf("\nPRODUTO NAO ENCONTRADO");
}


void RemoverProduto(ListaProdutos *carrinho, char nome[]) {
    if (carrinho->inicio == NULL) {
        printf("\nCarrinho vazio!\n");
        return 0;
    }
    No *aux = carrinho->inicio;
    while (aux != NULL) {
        if (strcmp(aux->prod.nome, nome) == 0) {
            if (aux == carrinho->inicio) {
                carrinho->inicio = aux->prox;
                if (carrinho->inicio != NULL)
                    carrinho->inicio->ant = NULL;
                else
                    carrinho->fim = NULL;
            }
            else if (aux == carrinho->fim) {
                carrinho->fim = aux->ant;
                carrinho->fim->prox = NULL;
            }
            else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }
            free(aux);
            carrinho->tamanho--;
            printf("\nProduto removido com sucesso!\n");
            return 1;
        }
        aux = aux->prox;
    }
    printf("\nProduto nao encontrado!\n");
    return 0;
}

float finalizarCarrinho(ListaProdutos *carrinho) {
    float total = 0;
    No *aux = carrinho->inicio;
    while (aux != NULL) {
        total += aux->prod.valor * aux->prod.quantidade;
        No *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    carrinho->inicio = NULL;
    printf("\nSUA COMPRA TEVE UM TOTAL DE %2.f reais",total);
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
