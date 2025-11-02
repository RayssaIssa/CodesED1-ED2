
void questao1(int option){
    int i, n;

    do{
        int soma = 0;
        printf("\nInsira a quantidade de elementos: ");
        scanf("%d", &n);

        int *vetor = malloc(n * sizeof(int));
        if(vetor == NULL){
            printf("\nErro ao alocar memoria!\n");
            return;
        }

        printf("\nInsira os elementos do vetor, separados por Enter: ");
        for(i = 0; i < n; i++){
            scanf("%d", &(vetor[i]));
            soma += vetor[i];
        }

        printf("\nA soma de todos os elementos e: %d\n", soma);

        free(vetor);

        printf("\nDeseja repetir a questao? (1- Sim, 0- Nao) ");
        scanf("%d", &option);
    }while(option != 0);
}