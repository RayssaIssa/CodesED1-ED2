
void questao2(int option){
    int i, n;

    do{
        printf("\nInsira a quantidade de nomes: ");
        scanf("%d", &n);
        getchar();

        char **nomes = malloc(n * sizeof(char *));
        if(nomes == NULL){
            printf("\nErro ao alocar memoria!\n");
            return;
        }
        for(i = 0; i < n; i++){
            nomes[i] = malloc(50 * sizeof(char));
            if (nomes[i] == NULL) {
                printf("\nErro ao alocar memoria!\n");
                return;
            }
        }

        printf("\nInsira os nomes, separados por Enter: ");
        for (i = 0; i < n; i++) {
            fgets(nomes[i], 50, stdin);
        }

        printf("\nNomes:\n");
        for(i = 0; i < n; i++){
            printf("%s", nomes[i]);
        }

        free(nomes);

        printf("\nDeseja repetir a questao? (1- Sim, 0- Nao) ");
        scanf("%d", &option);
    }while(option != 0);
}