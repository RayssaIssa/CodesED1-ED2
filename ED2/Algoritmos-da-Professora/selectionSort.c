#include<stdio.h>
#include <stdlib.h>

void selectionSort(int *vetor, int tamanho){
    int i = 0, j = 0, auxiliar = 0;
 
    for(i = 0; i < tamanho; i++){
        int menor = i;
        for(j = i + 1; j < tamanho; j++){
            if( vetor[j] < vetor[menor] ){
                menor = j;
            }
        }
        auxiliar = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = auxiliar;
    }
}

int main (){
    int vetor[10] = {10,9,8,7,6,5,4,3,1,2};

    printf("\nVetor antes da ordenacao\n");
    for (int i = 0; i < 10; i++){
         printf("[%d] ",vetor[i]);
    }

    selectionSort(vetor, 10);

    printf("\n\nVetor ordenado\n");
    for (int i = 0; i < 10; i++){
        printf("[%d] ",vetor[i]);
    }
    return 0;
}