/* Qual é o vetor resultante após as 4 primeiras trocas ao executar ordenação por seleção com o seguinte vetor inicial {26 65 45 73 10 18 78 93 70 49 23 22} ?*/

#include <stdio.h>

void exibir(int vetor[], int tamanho) {
    printf("\n\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

void selectionSort(int vetor[], int tamanho) {
    for(int i = 0; i <= tamanho - 1; i++){
        int menor = i;
        for(int j = i + 1; j <= tamanho - 1; j++){
            if(vetor[menor] > vetor[j]){
                menor = j;
            }
        }
        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
        if (i == 3) {
            printf("\nO vetor resultante apos 4 trocas e:\n");
            exibir(vetor, tamanho);
        }
    }
}

int main(){
    int vetor[12] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
    selectionSort(vetor, 12);
    return 0;
}