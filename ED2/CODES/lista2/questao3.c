/*Considere a ordenação de n números armazenados no arranjo A, localizando primeiro o menor elemento de A e permutando esse elemento contido em A[1]. Em seguida, encontre o segundo menor elemento de A e o troque pelo elemento A[2]. Continue dessa maneira para os primeiros n − 1 elementos de A. Escreva um programa para esse algoritmo conhecido como ordenação por seleção.*/

#include <stdio.h>

void exibir(int vetor[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

void selectioSort(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (vetor[menor] > vetor[j]) {
                menor = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
        printf("\nIteracao %d", i);
        exibir(vetor, n);
    }
}

int main() {
    int tamanho = 10;
    int vetor[tamanho];
    printf("\nInsira os elementos do vetor: ");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    printf("\nVetor original");
    exibir(vetor, tamanho);
    printf("\nVetor sendo organizado");
    selectioSort(vetor, tamanho);
    return 0;
}