
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particionar(int vetor[], int inicio, int fim) {
    int numAleatorio = rand() % (fim - inicio + 1) + inicio;

    // Coloca o pivô aleatório no fim
    int aux = vetor[numAleatorio];
    vetor[numAleatorio] = vetor[fim];
    vetor[fim] = aux;

    int pivo = vetor[fim];
    int i = inicio - 1, j;

    //Compara enquanto o j for menor ou igual ao fim - 1
    for (j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }

    //Coloca o pivo no lugar correto
    aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;
    return i + 1;
}

void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}

void intercalar(int vetor[], int tamanho) {
    int meio = tamanho/2;
    int i = 0, j = meio, k = 0;
    int aux[tamanho];

    while (i < meio && j < tamanho) {
        if (vetor[i] <= vetor[j]) {
            aux[k] = vetor[i++];
        }else {
            aux[k] = vetor[j++];
        }
        k++;
    }
    if (i == meio) {
        while (j < tamanho) {
            aux[k++] = vetor[j++];
        }
    }else {
        while (i < meio) {
            aux[k++] = vetor[i++];
        }
    }
    for (i = 0; i < tamanho; i++) {
        vetor[i] = aux[i];
    }
}

void mergeSort(int vetor[], int tamanho) {
    int meio = tamanho/2;
    if (tamanho > 1) {
        mergeSort(vetor, meio);
        mergeSort(vetor + meio, tamanho - meio);
        intercalar(vetor, tamanho);
    }
}

void exibir(int vetor[], int tamanho) {
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }
}

int main() {
    // Inicializa o gerador de números aleatórios uma única vez
    srand(time(NULL));

    int tamanho;
    printf("\nQual o tamanho do vetor? ");
    scanf("%d", &tamanho);

    printf("\nDigite os elementos do vetor separados por espaco: ");
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor nao ordenado");
    exibir(vetor, tamanho);

    //quickSort(vetor, 0, tamanho - 1);
    mergeSort(vetor, tamanho);

    printf("\nVetor ordenado");
    exibir(vetor, tamanho);

    return 0;
}