#include <stdio.h>
#include <stdlib.h>

int i;

int alocaEzeraVetor(int n, int **vetor){
    *vetor = malloc(n * sizeof(int));
    if(*vetor == NULL){
        return 0;
    }

    for(i = 0; i < n; i++){
        (*vetor)[i] = 0;
    }
    return 1;
}

void imprimeVetor(int n, int *vetor){
    for(i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
}

void preencheVetor(int *vetor, int n){
    for(i = 0; i < n; i++){
        printf("\nDigite o numero para preencher o vetor: ");
        scanf("%d", &vetor[i]);
    }
}

int main(){
    int n;
    printf("\nDigite a quantidade de elementos: ");
    scanf("%d", &n);

    int *v = (int *)malloc(n *(sizeof(int)));
    if(v == NULL){
        return 1;
    }    

    for(i = 0; i < n; i++){
        v[i] = 100 * i;
        printf("%d\n", v[i]);
    }
    free(v);
    
    printf("\nDigite a quantidade de elementos: ");
    scanf("%d", &n);

    int *newVetor = NULL;

    if(alocaEzeraVetor(n, &newVetor)){
        preencheVetor(newVetor, n);
        printf("\nVetor Preenchido: ");
        imprimeVetor(n, newVetor);
    }else{
        printf("\nMemoria nao alocada\n");
    }
    
    free(newVetor);

    return 0;
}