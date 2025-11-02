
struct aluno { 
    char nome[81]; 
    char matricula[8]; 
    char turma; 
    float p1; 
    float p2; 
    float p3; 
};  


void criarCadastroQ4(struct aluno *Aluno){
    printf("\nCadastro do Aluno: \n");
    printf("\nNome: ");
    scanf("%s", Aluno->nome);
    printf("\nMatricula: ");
    scanf("%s", Aluno->matricula);
    printf("\nTurma: ");
    scanf(" %c", &Aluno->turma);
    while ((getchar()) != '\n');
    printf("\nNota da prova 1: ");
    scanf("%f", &Aluno->p1);
    printf("\nNota da prova 2: ");
    scanf("%f", &Aluno->p2);
    printf("\nNota da prova 3: ");
    scanf("%f", &Aluno->p3);
    printf("\nAluno cadastrado!\n\n");
}

float mediaFinalQ4(float n1, float n2, float n3){
    float media = (n1 + n2 + n3)/3;
    return media;
}

void imprimirCadastroQ4(struct aluno *Aluno){
    printf("\n\tDados do Aluno: \n");
    printf("Nome: %s\nMatricula: %s\tTurma: %c\nNota 1: %.1f\tNota 2: %.1f\tNota 3: %.1f\nMedia final: %.1f\n\n", Aluno->nome, Aluno->matricula, Aluno->turma, Aluno->p1, Aluno->p2, Aluno->p3, mediaFinalQ4(Aluno->p1, Aluno->p2, Aluno->p3));

}

void questao4(int option){
    struct aluno *Aluno;
    char cad;
    Aluno = malloc(sizeof(struct aluno));
    do{
        printf("\n\t--- Bem vindo ao Cadastro de alunos ---\n");
        do{
            printf("Deseja cadastrar um aluno? S - sim ou N - nao: ");
            scanf(" %c", &cad);
            if(cad == 'S'){
                criarCadastroQ4(Aluno);
                printf("\nDeseja imprimir os dados do aluno? S - sim ou N - nao: ");
                scanf(" %c", &cad);
                if(cad == 'S'){
                    imprimirCadastroQ4(Aluno);
                }else if(cad == 'N'){
                    break;
                }else{
                    printf("\nOpcao invalida!\n");
                }
            }else if(cad == 'N'){
                break;;
            }else{
                printf("\nOpcao invalida!\n");
            }            
        }while(cad != 'N');
        printf("\nDeseja retornar as questoes ou cadastrar novamente? 0 - Retornar as questoes 1 - Cadastrar novamente: ");
        scanf("%d", &option);
    } while (option != 0);
    free(Aluno);
}