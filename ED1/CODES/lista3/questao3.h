
void questao3(int option){
    int i, j, m, n;

    do{
        printf("\nInsira a quantidade de linhas da matriz: ");
        scanf("%d", &m);
        printf("\nInsira a quantidade de colunas da matriz: ");
        scanf("%d", &n);

        int **matriz = malloc(m * sizeof(int *));
        if(matriz == NULL){
            printf("\nErro ao alocar memoria!\n");
            return;
        }
        for(i = 0; i < m; i++){
            matriz[i] = malloc(n * sizeof(int));
            if (matriz[i] == NULL) {
                printf("\nErro ao alocar memoria!\n");
                return;
            }
        }

        printf("\nInsira os valores da matriz separados por Enter: ");
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("\nMatriz:\n\n");
        for(i = 0; i < m; i++){
            printf("[ ");
            for(j = 0; j < n; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("]\n");
        }

        free(matriz);

        printf("\nDeseja repetir a questao? (1- Sim, 0- Nao) ");
        scanf("%d", &option);
    }while(option != 0);
}
