/*Escreva um programa que receba do usuário o nome e a idade de uma pessoa e armazene essas informações numa estrutura de fila. Utilizando somente operações de enfileirar e desenfileirar, o seu programa deve remover um item através do nome fornecido pelo usuário. Ao final da execução da função, a fila deve ser igual à original, exceto pela ausência do item removido*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 5

struct dados{
    char nome[10];
    int idade;
};

typedef struct{
    struct dados pessoa[TAM];
    int fim, inicio;
} Pessoa;

void inicializa(Pessoa *p){
    p->fim = -1;
    p->inicio = 0;
}

void inserir(Pessoa *p, char *nome, int idade){
    if(p->fim == TAM-1){
        printf("\nFila cheia\n");
    }else{
        p->fim++;
        p->pessoa[p->fim].idade = idade;
        strcpy(p->pessoa[p->fim].nome, nome);
        printf("\nPessoa %s inserida\n", nome);
    }
}

void remover(Pessoa *p, char *nome){
    if(p->inicio > p->fim){
        printf("\nFila vazia\n");
    }else{
        Pessoa novaFila;
        inicializa(&novaFila);
        int removido = 0, i;

        for(i = p->inicio; i <= p->fim; i++){
            if(strcmp(p->pessoa[i].nome, nome) != 0){
                inserir(&novaFila, p->pessoa[i].nome, p->pessoa[i].idade);
            } else {
                removido = 1;
                //p->inicio++;
            }
        }
        if(removido){
            *p = novaFila;
            printf("\nPessoa %s removida da fila", nome);
        }
    }
}

void consultaFila(Pessoa* p){
    printf("\nO inicio da fila: %d\tO fim da fila: %d\n", p->inicio, p->fim);
}

int existePessoa(Pessoa* p, char *nome){
    int i;
    for(i = p->inicio; i <= p->fim; i++){
        if(strcmp(p->pessoa[i].nome, nome) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    int idade;
    char nome[10];

    Pessoa pessoa;
    inicializa(&pessoa);
    consultaFila(&pessoa);

    int opc = 11;
    do{
        printf("\n\tMenu\n0- Sair\n1- Inserir pessoa na fila\n2- Remover pessoa da fila\n");
        printf("Insira sua opcao: ");
        scanf("%d", &opc);

        switch (opc){
            case 0:
                printf("\nSaindo...");
                break;

            case 1:
                printf("\nInsira o nome: ");
                scanf("%s", nome);
                printf("\nInsira a idade: ");
                scanf("%d", &idade);
                inserir(&pessoa, nome, idade);
                consultaFila(&pessoa);
                break;

            case 2:
                printf("\nQual o nome da pessoa a remover? ");
                scanf("%s", nome);
                if(existePessoa(&pessoa, nome)){
                    remover(&pessoa, nome);
                    consultaFila(&pessoa);
                }else{
                    printf("\nPessoa nao encontrada\n");
                }
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
    }while (opc != 0);  
    return 0;
}