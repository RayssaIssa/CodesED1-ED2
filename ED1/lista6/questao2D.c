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

struct aviao{
    char nome[10]; 
    int id;
};

typedef struct FILA{
    struct aviao dados;
    struct FILA *prox;
} *Avioes;

int totalAvioes = 0;    //Global do numero de avioes

Avioes criarNovo(char *nome, int id){
    Avioes novo = (Avioes) malloc(sizeof(struct FILA));
    if(novo == NULL){
        printf("\nNao foi possivel alocar memoria");
        return NULL;
    }
    strcpy(novo->dados.nome, nome);
    novo->dados.id = id;
    novo->prox = NULL;
    return novo;
}

Avioes inserir(Avioes a, char *nome, int id){
    Avioes novo = criarNovo(nome, id);
    if(novo == NULL){
        return a;
    }
    if(a == NULL){
        totalAvioes++;
        return novo;
    }else{
        Avioes aux = a;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        totalAvioes++;
        printf("\nAviao %s com id %d inserido\n", nome, id);
        return a;
    }
}

void exibirLista(Avioes a){
    Avioes aux = a;
    printf("\n====================================");
    printf("\n\tLista de Espera\n");
    while(aux != NULL){
        printf(" [Aviao %s] ", aux->dados.nome);
        aux = aux->prox;
    }
    printf("\n====================================");
}

Avioes removerPrimeiro(Avioes a){
    if(a == NULL){
        printf("\nNao ha avioes na fila de espera\n");
        return a;
    }
    printf("\nAviao %s de id %d decolou!\n", a->dados.nome, a->dados.id);
    Avioes aux = a;
    a = a->prox;
    totalAvioes--;
    free(aux);
    aux = NULL;
    return a;
}

int main(){
    int opc = 111;
    Avioes aviao = NULL;
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
                printf("\nAutorizando a decolagem do primeiro aviao...");
                aviao = removerPrimeiro(aviao);
                exibirLista(aviao);
                break;

            case 3:
                printf("\nInsira o nome do aviao: ");
                char nome[10];
                scanf("%s", nome);
                printf("\nInsira o id do aviao: ");
                int id;
                scanf("%d", &id);
                aviao = inserir(aviao, nome, id);
                exibirLista(aviao);
                break;
                
            case 4:
                exibirLista(aviao);
                break;
            
            case 5:
                printf("\nPrimeiro aviao na fila:\tNome: %s, Identificador: %d\n", aviao->dados.nome, aviao->dados.id);
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(opc != 0);
    free(aviao);
    return 0;
}