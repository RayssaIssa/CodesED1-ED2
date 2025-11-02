#include <stdio.h>

void bubbleSort(int vetor[], int tam){
    int i, j, aux;
    for(i = 0; i < tam-1; i++){
        for(j = 0; j < tam-1-i; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void selectionSort(int vetor[], int tam){
    int i, j, aux;
    for(i = 0; i <= tam - 1; i++){
        int menor = i;
        for(j = i + 1; j <= tam - 1; j++){
            if(vetor[menor] > vetor[j]){
                menor = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}

void exibir(int vetor[], int n){
    printf("\n");
    int i;
    for(i = 0; i < n; i++){
        printf("[%d] ", vetor[i]);
    }
}

int main(){
    int tamanho, i;

    printf("\nQual a quantidade de elementos que deseja inserir? ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    printf("\nInsira os elementos separados por Enter: ");
    for(i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor antes da ordenacao:");
    exibir(vetor, tamanho);

    //selectionSort(vetor, tamanho);

    bubbleSort(vetor, tamanho);

    printf("\nVetor depois da ordenacao:");
    exibir(vetor, tamanho);

    return 0;
}