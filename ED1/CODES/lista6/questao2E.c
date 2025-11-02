/* Escreva um programa que simule o controle de uma pista de decolagem de aviões em um aeroporto. Neste programa, o usuário deve ser capaz de realizar as seguintes tarefas:  
a) Listar o número de aviões aguardando na fila de decolagem;  
b) Autorizar a decolagem do primeiro avião da fila;  
c) Adicionar um avião à fila de espera;  
d) Listar todos os aviões na fila de espera;  
e) Listar as características do primeiro avião da fila. 
Considere que os aviões possuem um nome e um número inteiro como identificador. Adicione outras características conforme achar necessário. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

struct aviao{
    char nome[10];
    int id;
};

typedef struct FILA{
    struct aviao dados[TAM];
    int inicio, fim;
} Avioes;

int totalAvioes = 0;    //Global do numero de avioes

void inicializa(Avioes *a){
    a->inicio = 0;
    a->fim = -1;
}

void inserir(Avioes *a, char *nome, int id){
    if(a->fim == TAM - 1){
        printf("\nFila cheia");
    }else{
        a->fim++;
        strcpy(a->dados[a->fim].nome, nome);
        a->dados[a->fim].id = id;
        totalAvioes++;
        printf("\nAviao %d inserido\n", id);
    }
}

void exibirLista(Avioes *a){
    //printf("\nPrimiro da fila e %d e o ultimo e %d", a->dados[a->inicio].id, a->dados[a->fim].id);
    int i;
    for(i = a->inicio; i <= a->fim; i++){
        printf("\tAviao %d", a->dados[i].id);
    }
}

void remover(Avioes *a){
    if(a->inicio > a->fim){
        printf("\nA fila esta vazia\n");
    }else{
        printf("\nAviao %d decolou\n", a->dados[a->inicio].id);
        a->inicio++;
        totalAvioes--;
    }
}

int main(){
    int opc = 111;
    Avioes aviao;
    inicializa(&aviao);
    do{
        printf("\n\tMenu\n\n0 - Sair\n1 - Listar o numero de avioes aguardando na fila de decolagem\n2 - Autorizar a decolagem do primeiro aviao da fila\n3 - Adicionar um aviao a fila de espera\n4 - Listar todos os avioes na fila de espera\n5 - Listar as caracteristicas do primeiro aviao da fila\n");
        printf("Digite a opcao escolhida: ");
        scanf("%d", &opc);
        switch(opc){
            case 0:
                printf("\nSaindo...\n");
                break;

            case 1:
                printf("\nNumero de avioes aguardando na fila de decolagem: %d\n", totalAvioes);
                break;

            case 2:
                printf("\nAutorizando a decolagem do primeiro aviao...\n");
                remover(&aviao);
                break;

            case 3:
                printf("\nInsira o nome do aviao: ");
                char nome[10];
                scanf("%s", nome);
                printf("\nInsira o id do aviao: ");
                int id;
                scanf("%d", &id);
                inserir(&aviao, nome, id);
                break;
                
            case 4:
                exibirLista(&aviao);
                break;
            
            case 5:
                printf("\nPrimeiro aviao na fila:\tNome: %s, Identificador: %d\n", aviao.dados[aviao.inicio].nome,aviao.dados[aviao.inicio].id);
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(opc != 0);
    return 0;
}