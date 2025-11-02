#include <stdio.h>
#include <string.h>

typedef struct Produtos{
    char nome[20];
    int tipo;
    float valor;
} Produtos;

int main(){
    Produtos *produto;
    char tipo[17];
    int quantidade, i;
    printf("\nCadastro de plantas\n");
    printf("\nQuantas plantas deseja cadastrar? ");
    scanf("%d", &quantidade);
    for(i = 0; i < quantidade; i++){
        printf("\nInsira o nome da planta: ");
        scanf("%s", produto[i].nome);
        printf("\nInsira o valor da planta: ");
        scanf("%f", &produto[i].valor);
        printf("\nQual o tipo da planta? 1 - Ambiente externo 2 - Ambiente Interno ");
        scanf("%d", &produto[i].tipo);
    }

    printf("\nPlantas cadastradas\n");
    for(i = 0; i < quantidade; i++){
        if(produto[i].tipo == 1){
            strcpy(tipo, "Ambiente externo");
        } else {
            strcpy(tipo, "Ambiente interno");
        }
        printf("\nNome: %s\tTipo: %s\tValor: R$%.2f\n", produto[i].nome, tipo, produto[i].valor);
    }
    return 0;
}