/* Uma ordenação por contagem de um vetor x de tamanho n é executada da seguinte forma: declare um vetor count e defina count[i] como o número de elementos menores que x[i]. Em seguida, coloque x[i] na posição count[i] de um vetor de saída (leve em consideração a possibilidade de elementos iguais). Escreva uma função para ordenar um vetor x de tamanho n usando esse método.*/

#include <stdio.h>

void exibir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d] ", v[i]);
    }
}

void ordenacao(int x[], int n) {
    int count[n], saida[n];
    for (int i = 0; i < n; i++) {
        count[i] = 0;
        saida[i] = 0;
        for (int j = 0; j < n; j++) {
            if (x[j] < x[i]) {
                count[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int pos = count[i];
        while (saida[pos] != 0) {
            pos++;
        }
        saida[pos] = x[i];
    }
    for (int i = 0; i < n; i++) {
        x[i] = saida[i];
    }
}

int main() {
    int tamanho;
    printf("\nInsira a quantidade de elementos: ");
    scanf("%d", &tamanho);
    int x[tamanho];
    printf("\nInsira os elementos de X: ");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &x[i]);
    }
    printf("\nVetor original: \t");
    exibir(x, tamanho);
    ordenacao(x, tamanho);
    printf("\nVetor ordenado: \t");
    exibir(x, tamanho);
    return 0;
}