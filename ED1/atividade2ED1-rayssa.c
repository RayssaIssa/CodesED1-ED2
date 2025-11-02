#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

struct Conta{
    float saldo;
    char nome[20];
    int numeroDaConta;
};

void deposito(struct Conta* conta, float valor){
    conta->saldo += valor;
}

float consulta(struct Conta* conta){
    return conta->saldo;
}

bool retirada(struct Conta* conta, float valor){
    if(conta->saldo >= valor){
        conta->saldo -= valor;
        return true;
    }else{
        return false;
    }
}

int main(){
    struct Conta conta;
    int option;
    float valor;
    printf("\nInsira as informacoes da conta\n");
    printf("Nome: ");
    scanf("%s", conta.nome);
    conta.saldo = 0.0;
    conta.numeroDaConta = 10010;

    printf("\nConta criada com sucesso!\n");

    printf("\n\t---- Conta ----\n");
    printf("0 - Finalizar operacao\n1 - Realizar deposito\n2 - Consultar saldo\n 3 - Realizar retirada\n");
    printf("\nSelecione a opcao desejada: ");
    scanf("%d", &option);
    while (option != 0){
    
        switch (option){
            case 0:
                printf("\nOperacao finalizada!\n");
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
        printf("\n\t---- Conta ----\n");
        printf("0 - Finalizar operacao\n1 - Realizar deposito\n2 - Consultar saldo\n 3 - Realizar retirada\n");
        printf("\nSelecione a opcao desejada: ");
        scanf("%d", &option);
    }
    return 0;
}