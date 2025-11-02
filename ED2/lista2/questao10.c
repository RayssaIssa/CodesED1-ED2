/* Um vetor v[p,r] está “arrumado” se existe j pertence [p, r] tal que v[p..j - 1]<v[j]<  v[j + 1.. r]. Escreva um algoritmo que decida se v[p,r] está arrumado. Em caso afirmativo, o seu algoritmo deve devolver o valor de j. */

#include <stdio.h>

int verificaArrumado(int vetor[], int inicio, int fim) {
    for (int i = inicio; i <= fim; i++) {
        int pertence = 1;
        for (int j = inicio; j < i; j++) {
            if (vetor[j] >= vetor[i]) {
                pertence = 0;
                break;
            }
        }
        if (pertence) {
            for (int j = i + 1; j <= fim; j++) {
                if (vetor[j] <= vetor[i]) {
                    pertence = 0;
                    break;
                }
            }
        }
        if (pertence) {
            return i;
        }
    }
    return -1;
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
    int j = verificaArrumado(vetor, 0, tamanho - 1);
    if(j != -1) {
        printf("\nJ = %d\n", vetor[j]);
    }else {
        printf("O vetor NAO está arrumado.\n");
    }
}