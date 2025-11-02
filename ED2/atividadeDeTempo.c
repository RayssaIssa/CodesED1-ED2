#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Minha-Biblioteca-C/bubbleSort.h"
#include "Minha-Biblioteca-C/selectSort.h"
#include "Minha-Biblioteca-C/insertionSort.h"
#include "Minha-Biblioteca-C/shellSort.h"
#include "Minha-Biblioteca-C/mergeSort.h"
#include "Minha-Biblioteca-C/quickSort.h"

void gerarVetorAleatorio(long *vetor, long tamanho, int min, int max) {
    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }
}


int main() {
    LARGE_INTEGER frequency, start, end;
    double elapsedTime;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    long tamanho = 1000000;
    long *vetor = (long *)malloc(tamanho * sizeof(long));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    gerarVetorAleatorio(vetor, tamanho, 0, 2000000);

    insertionSort(vetor, tamanho);

    QueryPerformanceCounter(&end);
    elapsedTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Tempo de execução: %f segundos\n", elapsedTime);
    free(vetor);

    return 0;
}