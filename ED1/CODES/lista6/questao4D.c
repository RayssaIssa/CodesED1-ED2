/*Seja A uma sequência formada por 20 números inteiros. Codifique um programa que armazene na fila A os números pares e na fila B os números impares. */

#include <stdio.h>
#include <stdlib.h>

typedef struct FILA{
    int numero;
    struct FILA *prox;
} *fila;

fila criarItem(int valor){
    fila novo = (fila) malloc(sizeof(struct FILA));
    if(novo == NULL){
        printf("\nNao foi possivel alocar memoria");
        return NULL;
    }
    novo->numero = valor;
    novo->prox = NULL;
    return novo;
}

fila adicionar(fila f, int valor){
    fila novo = criarItem(valor);
    if(novo == NULL){
        return f;
    }else if(f == NULL){
        printf("\nItem %d inserido", valor);
        return novo;
    }else{
        fila auxiliar = f;
        while(auxiliar->prox != NULL){
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = novo;
        printf("\nItem %d inserido", valor);
        return f;
    }
}

fila pares(fila f){
    fila auxiliar = f;
    fila par = NULL;
    while(auxiliar->prox != NULL){
        if(auxiliar->numero % 2 == 0){
            par = adicionar(par, auxiliar->numero);
        }
        auxiliar = auxiliar->prox;
    }
    return par;
}

fila impares(fila f){
    fila auxiliar = f;
    fila impar = NULL;
    while(auxiliar->prox != NULL){
        if(auxiliar->numero % 2 != 0){
            impar = adicionar(impar, auxiliar->numero);
        }
        auxiliar = auxiliar->prox;
    }
    return impar;
}

void exibirFila(fila f){
    fila aux = f;
    printf("[");
    while(aux != NULL){
        printf(" %d", aux->numero);
        aux = aux->prox;
    }
    printf(" ]\n");
}

int main(){
    fila original = NULL;
    fila filaA = NULL;
    fila filaB = NULL;
    int i, valor = 0;
    
    printf("\nInserindo valores da lista original, por favor digite os numeros e de enter entre eles.\n");
    for(i = 0; i < 20; i++){
        printf("\nInsira um numero: ");
        scanf("%d", &valor);
        original = adicionar(original, valor);
    }
    filaA = pares(original);
    filaB = impares(original);

    int opc = 111;
    do{
        printf("\nMenu\n0 - Sair\n1 - Exibir lista original\n2 - Exibir lista dos pares\n3 - Exibir lista do impares\n");
        scanf("%d", &opc);

        switch(opc){
            case 0:
                printf("\nSaindo...");
                break;
            case 1:
                printf("\nFila original\n");
                exibirFila(original);
                break;
            case 2:
                printf("\nFila A - Pares\n");
                exibirFila(filaA);
                break;
            case 3:
                printf("\nFila B - Impares\n");
                exibirFila(filaB);
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(opc != 0);

    free(original);
    free(filaA);
    free(filaB);
    return 0;
}