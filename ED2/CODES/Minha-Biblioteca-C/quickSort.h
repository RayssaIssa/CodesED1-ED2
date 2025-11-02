#ifndef ESTRUTURA_DE_DADOS_2_QUICKSORT_H
#define ESTRUTURA_DE_DADOS_2_QUICKSORT_H

int particionar(long *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1, j;

    //Compara enquanto o j for menor ou igual ao fim - 1
    for (j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            int aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }

    //Coloca o pivo no lugar correto
    int aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;
    return i + 1;
}

void quickSort(long *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}


#endif //ESTRUTURA_DE_DADOS_2_QUICKSORT_H