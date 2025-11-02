/* Escreva um algoritmo que ordene de maneira decrescente (do maior para o menor).*/

#include <stdio.h>

void exibir(int vetor[], int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

void ordenaDescrecente(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        int maior = i;
        for(int j = i + 1; j < n; j++){
            if (vetor[maior] < vetor[j]) {
                maior = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
    }
}

int main() {
    int tamanho = 5;
    int vetor[tamanho];
    printf("\nInsira os elementos do vetor: ");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    printf("\nVetor original");
    exibir(vetor, tamanho);
    ordenaDescrecente(vetor, tamanho);
    printf("\nVetor em ordem descrescente");
    exibir(vetor, tamanho);
    return 0;
}