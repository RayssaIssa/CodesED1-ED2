
struct estudantes{
    char firstName[50];
    char lastName[50];
    float ip;
};

struct funcionarios{
    char firstName[50];
    char lastName[50];
    float salario;
};

int i, j, quant;
int numFuncionarios = 0, numEstudantes = 0;
struct funcionarios* funcionario = NULL;
struct estudantes* estudante = NULL;

int compararNomes(const void* registroA, const void* registroB) {
    const struct funcionarios* a = (const struct funcionarios*)registroA;
    const struct funcionarios* b = (const struct funcionarios*)registroB;
    int comparar = strcmp(a->lastName, b->lastName);
    return (comparar == 0) ? strcmp(a->firstName, b->firstName) : comparar;
}

void ordenaNomes(void* registro, int tamanho, size_t tamanhoStruct) {
    qsort(registro, tamanho, tamanhoStruct, compararNomes);
}

bool verificaNomes(int tamanho, void* lista, char primeiroNome[], char sobrenome[], int tipo) {
    if (tipo == 1) {    //Para os Funcionários
        struct funcionarios* listaF = (struct funcionarios*) lista;
        for (i = 0; i < tamanho; i++) {
            if (strcmp(listaF[i].lastName, sobrenome) == 0 && strcmp(listaF[i].firstName, primeiroNome) == 0) {
                return false;  // Nome já existe
            }
        }
    } else {    //Para os Estudantes
        struct estudantes* listaE = (struct estudantes*) lista;
        for (i = 0; i < tamanho; i++) {
            if (strcmp(listaE[i].lastName, sobrenome) == 0 && strcmp(listaE[i].firstName, primeiroNome) == 0) {
                return false;  // Nome já existe
            }
        }
    }
    return true;
}

void aumentoSalario(struct funcionarios* funcionario){
    funcionario->salario *= 1.1;
}

void verificaAumento() {
    bool aumentoDado = false;
    for(i = 0; i < numFuncionarios; i++){
        for(j = 0; j < numEstudantes; j++){
            if (strcmp(funcionario[i].firstName, estudante[j].firstName) == 0 && 
                strcmp(funcionario[i].lastName, estudante[j].lastName) == 0 && estudante[j].ip > 3.0) {
                aumentoSalario(&funcionario[i]);
                printf("\nFuncionario %s %s recebeu aumento! Novo salario: R$%.2f\n\n", 
                    funcionario[i].firstName, funcionario[i].lastName, funcionario[i].salario);
                    aumentoDado = true;
            }
        }
    }
    if(!aumentoDado){
        printf("\nSem aumentos para os funcionarios!\n");
    }
}

/*  PARA TESTES
void listarRegistrosF(){
    for(i = 0; i < numFuncionarios; i++){
        printf("\nNome: %s %s e R$%.1f\n", funcionario[i].firstName, funcionario[i].lastName, funcionario[i].salario);
    }
}
void listarRegistrosE(){
    for(i = 0; i < numEstudantes; i++){
        printf("\nNome: %s %s e IP: %.1f\n", estudante[i].firstName, estudante[i].lastName, estudante[i].ip);
    }
}*/

void isereNomes(int option){
    do{
        printf("\n\tMenu\n\n1- Registrar nomes de funcionarios\n2- Registrar nomes de estudantes\n3- Verificar funcionarios disponiveis para aumento\n0- Sair/Voltar as questoes\n\nDigite o numero escolhido: ");
        scanf("%d", &option);

        switch (option){
        case 1:
            printf("\n\tRegistro de funcionarios\n");
            printf("\nQual a quantidade de funcionarios a serem registrados? ");
            scanf("%d", &quant);

            funcionario = realloc(funcionario, (numFuncionarios + quant) * sizeof(struct funcionarios));
            if (!funcionario) {
                printf("\nErro ao alocar memoria!\n");
                exit(1);
            }

            for(i = numFuncionarios; i < numFuncionarios + quant; i++){
                printf("\nDigite o primeiro nome do funcionario: ");
                scanf("%s", funcionario[i].firstName);
                printf("\nDigite o sobrenome do funcionario: ");
                scanf("%s", funcionario[i].lastName);

                if (!verificaNomes(i, funcionario, funcionario[i].firstName, funcionario[i].lastName, 1)) {
                    printf("\nNome ja registrado! Tente outro.\n");
                    i--; // Voltar para o mesmo índice
                    continue;
                }

                printf("\nDigite o salario do funcionario: ");
                scanf("%f", &funcionario[i].salario);
            }
            numFuncionarios += quant;
            ordenaNomes(funcionario, numFuncionarios, sizeof(struct funcionarios));
            //listarRegistrosF(numFuncionarios, funcionario);
            break;

        case 2:
            printf("\n\tRegistro de estudantes\n");
            printf("\nQual a quantidade de estudantes a serem registrados? ");
            scanf("%d", &quant);

            estudante = realloc(estudante, (numEstudantes + quant) * sizeof(struct estudantes));
            if (!estudante) {
                printf("\nErro ao alocar memoria!\n");
                exit(1);
            }

            for(i = numEstudantes; i < numEstudantes + quant; i++){
                printf("\nDigite o primeiro nome do estudante: ");
                scanf("%s", estudante[i].firstName);
                printf("\nDigite o sobrenome do estudante: ");
                scanf("%s", estudante[i].lastName);

                if (!verificaNomes(i, estudante, estudante[i].firstName, estudante[i].lastName, 2)) {
                    printf("\nNome ja registrado! Tente outro.\n");
                    i--; // Voltar para o mesmo índice
                    continue;
                }

                printf("\nDigite o Indice de pontos de graduacao do estudante: ");
                scanf("%f", &estudante[i].ip);
            }
            numEstudantes += quant;
            ordenaNomes(estudante, numEstudantes, sizeof(struct estudantes));
            //listarRegistrosE(numEstudantes, estudante);
            break;

        case 3:
            printf("\nVerificando se ha funcionarios para receber aumento...\n");
            if (numFuncionarios > 0 && numEstudantes > 0) {
                verificaAumento();
            } else {
                printf("\nNao ha registros suficientes para verificacao.\n");
            }
            break;

        case 0:
            printf("\nSaindo...\n");
            free(funcionario);
            free(estudante);
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }

    }while(option != 0);
}
