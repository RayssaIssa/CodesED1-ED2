/*Existem partes de sistemas operacionais que cuidam da ordem em que os programas devem ser executados. Por exemplo, em um sistema de computação de  tempocompartilhadao (“time-shared”) existe a necessidade de manter um conjunto de processo em uma fila, esperando para serem executados. Escreva um programa que seja capaz de ler uma série de solicitações para:  
a) Incluir novos processos na fila de processo; 
b) Retirar da fila o processo com o maior tempo de espera;  
c) Imprimir o conteúdo da lista de processo em determinado momento. 
Assuma que cada processo é representado por um registro composto por um número identificador do processo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

struct listaP{
    int id;
    char nome[10];
    int tempoEspera;
};

typedef  struct FILA{
    struct listaP processo[TAM];
    int inicio, fim;
} fila;
int tempo = 100;

void inicializa(fila *f){
    f->inicio = 0;
    f->fim = -1;
}

void adicionar(fila *f, char *nome, int id){
    if(f->fim == TAM - 1){
        printf("\nFila cheia\n");
    }else{
        f->fim++;
        f->processo[f->fim].id = id;
        f->processo[f->fim].tempoEspera = tempo;
        tempo--;
        strcpy(f->processo[f->fim].nome, nome);
        printf("\nProcesso %d inserido\n", id);
    }
}

void remover(fila *f){
    if (f->inicio > f->fim) {
        printf("\nFila vazia.\n");
        return;
    }
    int i, posMaior = f->inicio;
    int maiorTempo = f->processo[f->inicio].tempoEspera;

    // Localiza o processo com maior tempo de espera
    for(i = f->inicio + 1; i <= f->fim; i++){
        if(f->processo[i].tempoEspera > maiorTempo){
            maiorTempo = f->processo[i].tempoEspera;
            posMaior = i;
        }
    }
    printf("\nProcesso %d com tempo de espera %d removido.\n", f->processo[posMaior].id, f->processo[posMaior].tempoEspera);

    // Desloca os elementos para preencher o "buraco"
    for(i = posMaior; i < f->fim; i++){
        f->processo[i] = f->processo[i + 1];
    }
    f->fim--;
}


void exibirFila(fila *f){
    int i;
    printf("\nProcessos na fila de espera\n");
    for(i = f->inicio; i <= f->fim; i++){
        printf("\nId: %d | Nome: %s | Tempo de espera: %d", f->processo[i].id, f->processo[i].nome, f->processo[i].tempoEspera);
    }
}

int main(){
    fila processos;
    inicializa(&processos);
    int opc = 111, id;
    char nome[10];
    do{
        printf("\nMenu\n0 - Sair\n1 - Incluir processo\n2 - Retirar processo com maior tempo de espera\n3 - Imprimir conteudo da lista de processo\n");
        scanf("%d", &opc);

        switch(opc){
            case 0:
                printf("\nSaindo...");
                break;
            case 1:
                printf("\nInserindo processo\n");
                printf("\nDigite o id do processo: ");
                scanf("%d", &id);
                printf("\nDigite o nome do processo: ");
                scanf("%s", nome);
                adicionar(&processos, nome, id);
                break;
            case 2:
                printf("\nProcurando processo com maior tempo de espera...\n");
                remover(&processos);
                break;
            case 3:
                exibirFila(&processos);
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(opc != 0);
    return 0;
}