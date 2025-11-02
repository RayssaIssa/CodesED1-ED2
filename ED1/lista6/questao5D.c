/*Existem partes de sistemas operacionais que cuidam da ordem em que os programas devem ser executados. Por exemplo, em um sistema de computação de  tempocompartilhadao (“time-shared”) existe a necessidade de manter um conjunto de processo em uma fila, esperando para serem executados. Escreva um programa que seja capaz de ler uma série de solicitações para:  
a) Incluir novos processos na fila de processo; 
b) Retirar da fila o processo com o maior tempo de espera;  
c) Imprimir o conteúdo da lista de processo em determinado momento. 
Assuma que cada processo é representado por um registro composto por um número identificador do processo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listaP{
    int id;
    char nome[10];
    int tempoEspera;
};

typedef  struct FILA{
    struct listaP processo;
    struct FILA *prox;
} *fila;
int tempo = 100;

fila criarItem(int id, char *nome){
    fila novo = (fila) malloc(sizeof(struct FILA));
    if(novo == NULL){
        printf("\nNao foi possivel alocar memoria");
        return NULL;
    }
    novo->processo.id = id;
    strcpy(novo->processo.nome, nome);
    novo->processo.tempoEspera = tempo;
    tempo--;
    novo->prox = NULL;
    return novo;
}

fila adicionar(fila f, int id, char *nome){
    fila novo = criarItem(id, nome);
    if(novo == NULL){
        return f;
    }else if(f == NULL){
        printf("\nProcesso %d inserido", id);
        return novo;
    }else{
        fila aux = f;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        printf("\nProcesso %d inserido\n", id);
        return f;
    }
}

fila remover(fila f){
    if(f == NULL){
        printf("\nFila de espera vazia\n");
        return f;
    }
    fila auxiliar = f;
    int maior = auxiliar->processo.tempoEspera;
    int id = auxiliar->processo.id;
    while(auxiliar != NULL){
        if(auxiliar->processo.tempoEspera > maior){
            maior = auxiliar->processo.tempoEspera;
            id = auxiliar->processo.id;
        }
        auxiliar = auxiliar->prox;
    }

    //Se for o primeiro elemento
    if(f->processo.id == id){
        fila temporario = f->prox;
        printf("\nProcesso %d com tempo de espera %d foi removido\n", f->processo.id, f->processo.tempoEspera);
        free(f);
        return temporario;
    }

    fila aux = f;
    fila auxFrente = f->prox;
    while(auxFrente != NULL){
        if(auxFrente->processo.id == id){
            aux->prox = auxFrente->prox;
            printf("\nProcesso %d com tempo de espera %d foi removido\n", id, auxFrente->processo.tempoEspera);
            free(auxFrente);
            auxFrente = NULL;            
            return f;
        }else{
            aux = auxFrente;
            auxFrente = auxFrente->prox;
        }
    }
    printf("\nERRO\n");
    return f;
}

void exibirFila(fila f){
    fila auxiliar = f;
    printf("\nProcessos na fila de espera\n");
    while(auxiliar != NULL){
        printf("\nId: %d | Nome: %s | Tempo de espera: %d", auxiliar->processo.id, auxiliar->processo.nome, auxiliar->processo.tempoEspera);
        auxiliar = auxiliar->prox;
    }
}

int main(){
    fila processos = NULL;
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
                processos = adicionar(processos, id, nome);
                break;
            case 2:
                printf("\nProcurando processo com maior tempo de espera...\n");
                processos = remover(processos);
                break;
            case 3:
                exibirFila(processos);
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(opc != 0);

    free(processos);
    return 0;
}