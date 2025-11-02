
struct REG{
    char nome[20];
    float salario;
    int idade;
    char sexo;
}registro; 

void insertDados(){
    int idade;
    char sexo;
    printf("\nInsira o nome: ");
    scanf("%s", registro.nome);

    printf("\nInsira o sexo (F ou M): ");
    while ((getchar()) != '\n');
    scanf("%c", &sexo);
    //fflush(stdin);
    if(sexo != 'M' && sexo != 'F'){
        printf("\nSexo invalido!\n");
        insertDados();
    }else{
        registro.sexo = sexo;
    }

    printf("\nInsira o salario: ");
    scanf("%f", &registro.salario);

    printf("\nInsira a idade: ");
    scanf("%d", &idade);
    if(idade < 0 || idade > 150){
        printf("\nIdade invalida!\n");
        insertDados();
    }else{
        registro.idade = idade;
    }
}

void regfunction(int option){
    do{
        printf("\nBem vindo ao registro de funcionario!\n");
        insertDados();
        printf("\nDados inseridos:\n-- Nome: %s\n-- Idade: %d\n-- Sexo: %c\n-- Salario: R$%.2f\n", registro.nome, registro.idade, registro.sexo, registro.salario);

        printf("\nDeseja registrar novamente? (1 - Sim ou 0 - Nao/Retornar as questoes) ");
        scanf("%d", &option);
    }while(option != 0);
}