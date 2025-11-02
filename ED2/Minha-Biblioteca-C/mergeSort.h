#ifndef ESTRUTURA_DE_DADOS_2_MERGESORT_H
#define ESTRUTURA_DE_DADOS_2_MERGESORT_H

void intercalar(long *vetor, long *aux, long tamanho) {
    long meio = tamanho/2;
    long i = 0, j = meio, k = 0;

    while (i < meio && j < tamanho) {
        if (vetor[i] <= vetor[j]) {
            aux[k] = vetor[i++];
        }else {
            aux[k] = vetor[j++];
        }
        k++;
    }
    while (i < meio) {
        aux[k++] = vetor[i++];
    }
    while (j < tamanho) {
        aux[k++] = vetor[j++];
    }

    for (i = 0; i < tamanho; i++) {
        vetor[i] = aux[i];
    }
}

void mergeSortInterno(long *vetor, long *aux, long tamanho) {
    if (tamanho > 1) {
        long meio = tamanho / 2;
        mergeSortInterno(vetor, aux, meio);
        mergeSortInterno(vetor + meio, aux, tamanho - meio);
        intercalar(vetor, aux, tamanho);
    }
}

void mergeSort(long *vetor, long tamanho) {
    long *aux = (long *)malloc(tamanho * sizeof(long));
    if (aux == NULL) {
        printf("Erro ao alocar memória auxiliar.\n");
        return;
    }
    mergeSortInterno(vetor, aux, tamanho);
    free(aux);
}

#endif //ESTRUTURA_DE_DADOS_2_MERGESORT_H