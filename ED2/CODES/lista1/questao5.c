/* Considere a ordenação de n números armazenados no arranjo A, localizando primeiro o menor elemento de A e permutando esse elemento contido em A[1]. Em seguida, encontre o segundo menor elemento de A e o troque pelo elemento A[2]. Continue dessa maneira para os primeiros n − 1 elementos de A. Escreva um programa para esse algoritmo conhecido como ordenação por seleção. */

#include <stdio.h>
#define n 10

void selectSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[menor] > vetor[j]) {
                menor = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}

void exibir(int vetor[], int tamanho) {
    printf("\n\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int A[n] = {2, 7, 9 ,0, 12, 43, 34, 22, 60, 10};

    exibir(A, n);
    selectSort(A, n);
    exibir(A, n);

    return 0;
}