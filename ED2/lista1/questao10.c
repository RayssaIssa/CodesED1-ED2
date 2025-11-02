/* Um vetor v[p,r] está “arrumado” se existe j pertence [p, r] tal que v[p..j1]<v[j]< v[j + 1.. r]. Escreva um algoritmo que decida se v[p,r] está arrumado. Em caso afirmativo, o seu algoritmo deve devolver o valor de j. (“arrumado” não significa ordenado) */

#include <stdio.h>

int arrumado(int vetor[], int inicio, int fim) {
    for(int j = inicio; j <= fim; j++) {
        int ok = 1;
        for(int i = inicio; i < j; i++) {
            if(vetor[i] >= vetor[j]) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            for(int i = j + 1; i <= fim; i++) {
                if(vetor[i] <= vetor[j]) {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) {
            return j;
        }
    }
    return -1;
}

int main() {
    int vetor[6] = {2, 3, 7, 5, 9, 11};

    int j = arrumado(vetor, 0, 5);

    if(j != -1) {
        printf("\nj = %d\n", vetor[j]);
    }else {
        printf("O vetor NAO está arrumado.\n");
    }
    return 0;
}