/* Faça um programa que seja capaz de ordenar uma lista encadeada utilizando o algoritmo selection sort. (**extra**: se você conseguir, implemente o mesmo algoritmo para ordenar uma lista duplamente encadeada. Qual a diferença, em termos de implementação, entre ordenar as duas estruturas?) */

#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA{
    int numero;
    struct LISTA *prox;
} *lista;

void exibir(lista l){
    lista aux = l;
    printf("\n\tLista\n");
    while(aux != NULL){
        printf("[%d] ", aux->numero);
        aux = aux->prox;
    }
    printf("\n");
}

lista criarNo(int valor){
    lista novo = (lista) malloc(sizeof(lista));
    if(novo == NULL){
        printf("\nNao foi possivel alocar memoria");
        return NULL;
    }
    novo->numero = valor;
    novo->prox = NULL;
    return novo;
}

lista adicionar(lista l, int valor){
    lista novo = criarNo(valor);
    if(novo == NULL){
        return l;
    }if(l == NULL){
        return novo;
    }
    lista aux = l;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return l;
}

void selectionSort(lista l) {
    lista aux = l;
    while (aux->prox != NULL) {
        int menor = aux->numero;
        while (aux->prox->prox != NULL) {
            if (menor > aux->prox->prox->numero) {
                menor = aux->prox->prox->numero;
            }
            aux = aux->prox;
        }
    }
}

int main(){

    return 0;
}