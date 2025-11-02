/* Escreva um algoritmo que receba valores em um vetor e imprima “ORDENADO” se o vetor estiver em ordem crescente. */

#include <stdio.h>

int verificaOrdenacao(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vetor[i] > vetor[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int tamanho = 10;
    int vetor[tamanho];
    printf("\nInsira os elementos do vetor: ");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    int ordenado = verificaOrdenacao(vetor, tamanho);
    if (ordenado) {
        printf("\nORDENADO\n");
    }else {
        printf("\nDesordenado\n");
    }
    return 0;
}