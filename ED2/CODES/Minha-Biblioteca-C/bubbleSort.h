#ifndef ESTRUTURA_DE_DADOS_2_BUBBLESORT_H
#define ESTRUTURA_DE_DADOS_2_BUBBLESORT_H

void bubbleSort(long *vetor, long tamanho){
    int i, j, aux;
    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - 1 - i; j++){
            if(vetor[j] > vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

#endif //ESTRUTURA_DE_DADOS_2_BUBBLESORT_H