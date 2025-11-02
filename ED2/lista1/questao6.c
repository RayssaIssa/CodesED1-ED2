/* Escreva um algoritmo que receba valores em um vetor e imprima “ORDENADO” se o vetor estiver em ordem crescente. (O seu algoritmo não deve ordenar o vetor, apenas verificar se ele está ordenado). */

#include <stdio.h>

int verificador(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[menor] > vetor[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    printf("\nInsira o tamanho do vetor: ");
    int tamanho;
    scanf("%d", &tamanho);
    printf("\nInsira os elementos do vetor: ");
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    int ordenado = verificador(vetor, tamanho);
    if (ordenado == 0) {
        printf("\nORDENADO\n");
    }else {
        printf("\nDesordenado\n");
    }
    return 0;
}