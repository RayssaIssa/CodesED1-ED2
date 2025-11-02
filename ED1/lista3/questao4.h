
typedef struct{
    char nome[50];
    int idade;
}Aluno;

void questao4(int option){
    int i, n;
    do{
        printf("\nInsira a quantidade de alunos: ");
        scanf("%d", &n);
        getchar();

        Aluno *aluno = malloc(n * sizeof(Aluno));
        if(aluno == NULL){
            printf("\nErro ao alocar memoria!\n");
            return;
        }
        
        for(i = 0; i < n; i++){
            printf("\n\tAluno %d", i+1);
            printf("\nInsira o nome do aluno: ");
            fgets(aluno[i].nome, 50, stdin);
            printf("Insira a idade do aluno: ");
            scanf("%d", &aluno[i].idade);
            getchar();
        }

        printf("\nAlunos registrados:\n");
        for(i = 0; i < n; i++){
            printf("\nNome: %sIdade: %d\n", aluno[i].nome, aluno[i].idade);
        }        

        free(aluno);

        printf("\nDeseja repetir a questao? (1- Sim, 0- Nao) ");
        scanf("%d", &option);
    }while(option != 0);
}
