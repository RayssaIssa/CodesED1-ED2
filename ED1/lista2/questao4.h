

void questao4(){
    int i;
    int *vetor = malloc(4 * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    printf("\nInsira 4 numeros separados por Enter: ");
    for(i = 0; i < 4; i++){
        scanf("%d", &(vetor[i]));
    }
    int maior = vetor[0], menor = vetor[0];
    for(i = 1; i < 4; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        }else if(vetor[i] < menor){
            menor = vetor[i];
        }
    }

    printf("\nO vetor e: [ ");
    for(i = 0; i < 4; i++){
        printf("%d ", vetor[i]);
    }
    printf("]");
    printf("\nO maior numero e: %d. O menor numero e: %d\n", maior, menor);

    free(vetor);
}