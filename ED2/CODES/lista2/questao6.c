/* Qual é o vetor resultante após as 4 primeiras trocas ao executar ordenação por inserção com o seguinte vetor inicial 26 65 45 73 10 18 78 93 70 49 23 22 ? */

#include <stdio.h>

void exibir(int vetor[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

void insertionSort(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        int chave = vetor[i], j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
        if (i == 3) {
            printf("\nTroca %d", i + 1);
            exibir(vetor, n);
        }

    }
}

int main() {
    int vetor[12] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
    insertionSort(vetor, 12);
    return 0;
}