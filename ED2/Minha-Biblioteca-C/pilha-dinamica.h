#include <stdio.h>
#include <stdlib.h>

// Funções para uma pilha dinâmica

typedef struct Pilha{
    int item;
    struct Pilha *prox;
}*Pilha;

Pilha criarItem(int valor){
    Pilha novoItem = (Pilha) malloc(sizeof(Pilha));
    if(novoItem == NULL){
        printf("\nNão foi possivel alocar memoria");
        return NULL;
    }else{
        novoItem->item = valor;
        novoItem->prox = NULL;
        return novoItem;
    }    
}

Pilha push(Pilha p, int valor){
    Pilha novoNo = criarItem(valor);
    novoNo->prox = p;
    return novoNo;
}

Pilha pop(Pilha p){
    if(p == NULL){
        printf("\nPilha Vazia\n");
        return p;
    }else{
        Pilha pilhaAuxiliar = p->prox;
        free(p);
        p = NULL;
        return pilhaAuxiliar;
    }
}