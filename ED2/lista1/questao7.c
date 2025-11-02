/* Escreva um algoritmo que ordene de maneira decrescente (do maior para o menor). */

#include <stdio.h>

void ordenarDecrecente(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[menor] < vetor [j]) {
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
    printf("\nInsira o tamanho do vetor: ");
    int n = 5;
    scanf("%d", &n);
    printf("\nInsira os elementos do vetor: ");
    int vetor[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    ordenarDecrecente(vetor, n);
    printf("\nVetor em ordem decrescente");
    exibir(vetor, n);
    return 0;
}