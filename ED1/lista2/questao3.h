
void questao3(){
    int i;
    int *vetor = malloc(6 * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    printf("\nInsera seis numeros separdos por Enter: ");
    for(i = 0; i < 6; i++){
        scanf("%d", &(vetor[i]));
    }

    for(i = 0; i < 6; i++){
        printf("\nPosicao: %d, Numero: %d, Endereco: %p", i, vetor[i], &(vetor[i]));
    }
    free(vetor);
}