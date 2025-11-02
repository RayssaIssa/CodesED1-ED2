#ifndef ESTRUTURA_DE_DADOS_2_INSERTIONSORT_H
#define ESTRUTURA_DE_DADOS_2_INSERTIONSORT_H

void insertionSort(long *vetor, long tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

#endif //ESTRUTURA_DE_DADOS_2_INSERTIONSORT_H