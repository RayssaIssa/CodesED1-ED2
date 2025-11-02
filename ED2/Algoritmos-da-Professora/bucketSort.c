#include <stdio.h>

void insertionSort(int v[6], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void bucketSort(int vetor[], int n) {
    
    //acha o maior valor que tem no vetor para depois saber quais serão os intervalos dos buckets
    int maximoValor = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > maximoValor)
            maximoValor = vetor[i];
    }

   int qtdBuckets = 5;

    //cada bucket será representado por um vetor e terá no máximo "n" elementos
    int buckets[5][n];    
    //é um vetor auxiliar que guarda quantos elementos tem em cada bucket. Inicialmente, cada um tem zero elementos
    int tamanho[5] = {0}; 

    //aqui é feito a distribuição dos valores do vetor em cada bucket correspondente 
    for (int i = 0; i < n; i++) {
        //percorre o vetor e decide em qual bucket cada número deve ser colocado. 
        int balde = (vetor[i] * qtdBuckets) / (maximoValor + 1);
        buckets[balde][tamanho[balde]++] = vetor[i];
    }
    
    /*for (int i = 0; i < 5; i++) {
        // Laço para percorrer colunas
        for (int j = 0; j < 5; j++) {
            printf("%d ", buckets[i] [j]);
        }
        printf("\n"); 
    }*/

    //ordena os baldes individualmente. Pode usar qlqr algoritmo
    for (int i = 0; i < qtdBuckets; i++) {
        if (tamanho[i] > 0) {
            insertionSort(buckets[i], tamanho[i]);
        }
    }

    //aqui junta os buckets de volta no vetor original
    int k = 0;
    for (int i = 0; i < qtdBuckets; i++) {
        for (int j = 0; j < tamanho[i]; j++) {
            vetor[k++] = buckets[i][j];
        }
    }
}

int main() {
    int vetor[10] = {29, 25, 3, 49, 9, 37, 21, 43, 31, 15};
    int n = 10;

    printf("VETOR SEM ORDEM:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    bucketSort(vetor, n);

    printf("\nVETOR EM ORDEM:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
