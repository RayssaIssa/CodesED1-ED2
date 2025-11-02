#ifndef ESTRUTURA_DE_DADOS_2_BUCKETSORT_H
#define ESTRUTURA_DE_DADOS_2_BUCKETSORT_H
#include "insertionSort.h"

void bucketSort(int vetor[], int n) {
    //Encontra o maior valor que tem no vetor para saber quais serão os intervalos dos buckets
    int maximoValor = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > maximoValor) {
            maximoValor = vetor[i];
        }
    }

    int qtdBuckets = 5;
    int buckets[5][n];      //Cada bucket é um vetor e terá no máximo "n" elementos
    int tamanho[5] = {0};   //Vetor que guarda quantos elementos tem em cada bucket

    //Faz a distribuição dos valores em cada bucket correspondente
    for (int i = 0; i < n; i++) {
        //Percorre o vetor e decide em qual bucket cada número deve ser colocado.
        int balde = (vetor[i] * qtdBuckets) / (maximoValor + 1);
        buckets[balde][tamanho[balde]++] = vetor[i];
    }

    //Ordena os baldes individualmente
    for (int i = 0; i < qtdBuckets; i++) {
        if (tamanho[i] > 0) {
            insertionSort(buckets[i], tamanho[i]);
        }
    }

    //Junta os buckets de volta no vetor original
    int k = 0;
    for (int i = 0; i < qtdBuckets; i++) {
        for (int j = 0; j < tamanho[i]; j++) {
            vetor[k++] = buckets[i][j];
        }
    }
}

#endif //ESTRUTURA_DE_DADOS_2_BUCKETSORT_H