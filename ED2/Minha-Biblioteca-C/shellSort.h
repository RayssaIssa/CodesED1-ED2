#ifndef ESTRUTURA_DE_DADOS_2_SHELLSORT_H
#define ESTRUTURA_DE_DADOS_2_SHELLSORT_H

void shellSort(long *vetor, long tamanho) {
    int i, j, chave;
    int intervalo = 1;
    while(intervalo < tamanho) {
        intervalo = 3 * intervalo + 1;
    }
    while (intervalo > 1) {
        intervalo /= 3;
        for(i = intervalo; i < tamanho; i++) {
            chave = vetor[i];
            j = i - intervalo;
            while (j >= 0 && chave < vetor[j]) {
                vetor [j + intervalo] = vetor[j];
                j -= intervalo;
            }
            vetor [j + intervalo] = chave;
        }
    }
}

#endif //ESTRUTURA_DE_DADOS_2_SHELLSORT_H