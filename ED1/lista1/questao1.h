
#include <stdbool.h>

struct contaBancaria{
    int numeroConta;
    char nome[30];
    float saldo;
};

void deposito(struct contaBancaria* conta, float valor){
    conta->saldo += valor;
}

float consulta(struct contaBancaria* conta){
    return conta->saldo;
}

bool retirada(struct contaBancaria* conta, float valor){
    if(conta->saldo >= valor){
        conta->saldo -= valor;
        return true;
    }else{
        return false;
    }
}

void iniciarConta(int option){
    float valor;
    struct contaBancaria conta;
    printf("\nBem vindo a abertura de sua conta!\n");
    printf("\nInsira seu nome: ");
    scanf("%s", conta.nome);
    printf("\nInsira o numero de sua conta: ");
    scanf("%i", &conta.numeroConta);
    printf("\nPara completar sua conta e preciso fazer um deposito de qualquer valor acima de 0. Digite a quantidade a ser depositada: ");
    scanf("%f", &valor);
    if(valor > 0){
        conta.saldo += valor;
        printf("\nConta criada com sucesso!\n");
    }else{
        printf("\nValor invalido!\n");
        iniciarConta(option);
    }
    do{
        printf("\n\t---- Conta ----\n");
        printf(" 0 - Finalizar operacao/Voltar as questoes\n 1 - Realizar deposito\n 2 - Consultar saldo\n 3 - Realizar retirada\n");
        printf("\nSelecione a opcao desejada: ");
        scanf("%d", &option);
        switch (option){
            case 0:
                printf("\nOperacao finalizada, retornando as questoes!\n");
                break;
            case 1:
                printf("\nInsira o valor do deposito: ");
                scanf("%f", &valor);
                if (valor > 0){
                    printf("%f", valor);
                    deposito(&conta, valor);
                    printf("\nDeposito realizada com sucesso!\n");
                }else{
                    printf("\nValor não pode ser nulo!\n");
                }
                break;
            case 2:
                printf("\nSaldo atual: R$%.2f", consulta(&conta));
                break;
            case 3:
                printf("\nInsira o valor da retirada: ");
                scanf("%f", &valor);
                if (retirada(&conta, valor)){
                    printf("\nRetirada realizada com sucesso!\n");
                }else{
                    printf("\nSaldo insuficiente!\n");
                }
                
                break;
            default:
                printf("\nOpção invalida!\n");
                break;
        }
    }while(option != 0);

    

}
