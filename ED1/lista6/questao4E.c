/*Seja A uma sequência formada por 20 números inteiros. Codifique um programa que armazene na fila A os números pares e na fila B os números impares. */

#include <stdio.h>
#include <stdlib.h>
#define TAM 20

typedef struct FILA{
    int numero[TAM], inicio, fim;
} fila;

void inicializa(fila *f){
    f->inicio = 0;
    f->fim = -1;
}

void adicionar(fila *f, int num){
    if(f->fim == TAM - 1){
        printf("\nFila cheia\n");
    }else{
        f->fim++;
        f->numero[f->fim] = num;
        printf("\nNumero %d inserido\n", num);
    }
}

void verifica(fila *f, fila *par, fila *impar){
    int i;
    for(i = f->inicio; i <= f->fim; i++){
        if(f->numero[i] % 2 == 0){
            adicionar(par, f->numero[i]);
        }else{
            adicionar(impar, f->numero[i]);
        }
    }
}

void exibirFila(fila *f){
    int i;
    printf("\n");
    for(i = f->inicio; i <= f->fim; i++){
        printf(" [%d]", f->numero[i]);
    }
    printf("\n");
}

int main(){
    fila original;
    fila filaA;
    fila filaB;
    inicializa(&original);
    inicializa(&filaA);
    inicializa(&filaB);

    int i, valor = 0;
    
    printf("\nInserindo valores da lista original, por favor digite os numeros e de enter entre eles.\n");
    for(i = 0; i < TAM; i++){
        printf("\nInsira um numero: ");
        scanf("%d", &valor);
        adicionar(&original, valor);
    }
    verifica(&original, &filaA, &filaB);

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
                exibirFila(&original);
                break;
            case 2:
                printf("\nFila A - Pares\n");
                exibirFila(&filaA);
                break;
            case 3:
                printf("\nFila B - Impares\n");
                exibirFila(&filaB);
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(opc != 0);
    return 0;
}