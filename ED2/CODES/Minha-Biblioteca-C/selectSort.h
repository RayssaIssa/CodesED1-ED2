#ifndef ESTRUTURA_DE_DADOS_2_SELECTSORT_H
#define ESTRUTURA_DE_DADOS_2_SELECTSORT_H

void selectionSort(long *vetor, long tamanho){
    int i, j, aux;
    for(i = 0; i <= tamanho - 1; i++){
        int menor = i;
        for(j = i + 1; j <= tamanho - 1; j++){
            if(vetor[menor] > vetor[j]){
                menor = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}

#endif //ESTRUTURA_DE_DADOS_2_SELECTSORT_H