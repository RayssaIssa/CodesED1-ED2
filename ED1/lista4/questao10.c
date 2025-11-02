#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int item;
    struct Pilha *prox;
}*Pilha;

Pilha criarItem(int valor){
    Pilha novoItem = (Pilha) malloc(sizeof(Pilha));
    if(novoItem == NULL){
        printf("\nNão foi possivel alocar memoria");
        return NULL;
    }
    novoItem->item = valor;
    novoItem->prox = NULL;
    return novoItem;   
}

Pilha push(Pilha p, int valor){
    Pilha novoNo = criarItem(valor);
    if (novoNo == NULL) return p;
    novoNo->prox = p;
    printf("\nElemento %d inserido na pilha", valor);
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

int main(){
    Pilha S = NULL;
    Pilha T = NULL;
    int remocao = 0;

    S = push(S, 3);
    T = push(T, 4);
    S = push(S, 5);
    S = push(S, 5);
    remocao += T->item;
    T = pop(T);
    T = push(T, 7);
    T = push(T, 8);
    remocao += S->item;
    S = pop(S);
    remocao += S->item;
    S = pop(S);
    remocao += T->item;
    T = pop(T);
    T = push(T, 9);

    printf("\nA soma dos elementos removidos e: %d\n", remocao);

    return 0;
}