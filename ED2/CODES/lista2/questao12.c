/*Implemente o algoritmo MergeSort para fazer ordenações decrescente. Exiba na tela para o usuário quantas comparações foram necessárias fazer usando o MergeSort para ordenar o conjunto de dados. */

#include <stdio.h>

int comparacoes = 0;

void intercalar(int vetor[], int tamanho) {
    int meio = tamanho/2;
    int i = 0, j = meio, k = 0;
    int aux[tamanho];
    while (i < meio && j < tamanho) {
        if (vetor[i] >= vetor[j]) {
            aux[k] = vetor[i++];
        }else {
            aux[k] = vetor[j++];
        }
        k++;
    }
    if (i == meio) {
        while (j < tamanho) {
            aux[k++] = vetor[j++];
        }
    }else {
        while (i < meio) {
            aux[k++] = vetor[i++];
        }
    }
    for (i = 0; i < tamanho; i++) {
        vetor[i] = aux[i];
    }
}

void mergeSort(int vetor[], int tamanho) {
    if (tamanho > 1) {
        comparacoes++;
        int meio = tamanho / 2;
        mergeSort(vetor, meio);
        mergeSort(vetor + meio, tamanho - meio);
        intercalar(vetor, tamanho);
    }
}

void exibir(int vetor[], const int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    printf("\nInsira o tamanho do vetor: ");
    scanf("%d", &tamanho);
    printf("\nInsira os elementos do vetor: ");
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    printf("\nVetor original\n");
    exibir(vetor, tamanho);
    mergeSort(vetor, tamanho);
    printf("\nVetor ordenado de maneira decrescente\n");
    exibir(vetor, tamanho);
    printf("\nQuantidade de comparacoes necessaria para a ordenacao: %d\n\n", comparacoes);
    return 0;
}