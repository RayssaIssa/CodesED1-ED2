/*Suponha um estacionamento que guarda até 7 carros. Os carros entram pela rua A e saem pela rua B. Se chegar um cliente para retirar um carro que não esteja estacionado na primeira vaga da rua B, todos os carros entre o carro do cliente e a rua B serão deslocados para fora do estacionamento, o carro do  cliente sairá do estacionamento e os outros carros voltarão a entrar pela entrada A na mesma ordem que saíram pela rua B. Observe que sempre que um carro deixa o estacionamento, todos os carros entre ele e a entrada A serão deslocados até o começo da rua B (da saída) de modo que, o tempo inteiro, todos os espaços vazios estão na entrada do estacionamento, ou seja na entrada pela rua A. 
Escreva um programa que simule o funcionamento deste estacionamento, usando a estrutura de dados adequada. O seu programa deve receber do usuário um número identificador de cada carro. O programa deve imprimir uma mensagem sempre que um carro chegar ou sair. Quando um carro chegar, a mensagem deve especificar se existe ou não vaga para o carro no estacionamento. Se não houver vaga, o carro não será inserido. Quando um carro sair do estacionamento, a mensagem deverá incluir o número de vezes em que o carro foi manobrado para fora do estacionamento para permitir que os outros carros saíssem*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 7

struct Carro{
    int id, manobras;
};

typedef struct estacionamento{
    struct Carro carro[TAM];
    int inicio, fim;
} fila;

void inicializa(fila *f){
    f->inicio = 0;
    f->fim = -1;
}

void adicionar(fila *f, int id){
    if(f->fim == TAM - 1){
        printf("\nEstacionamento cheio\n");
    }else{
        f->fim++;
        f->carro[f->fim].id = id;
        f->carro[f->fim].manobras = 0;
        printf("\nCarro %d entrou no estacionamento\n", id);
    }
}

int existe(fila *f, int id){
    if(f->inicio > f->fim){
        printf("\nO estacionamento esta vazio\n");
        return 0;
    }
    int i;
    for(i = f->inicio; i <= f->fim; i++){
        if(f->carro[i].id == id){
            return 1;
        }
    }
    return 0;
}

int verificaPosicao(fila *f, int id){
    if(f->carro[f->inicio].id == id){
        return 1;
    }else{
        return 0;
    }
}

void manobra(fila *f, int id) {
    struct Carro aux[TAM];
    int auxCount = 0;
    int i, j, pos = -1;

    //Encontra a posição do carro a ser removido
    for (i = f->inicio; i <= f->fim; i++) {
        if (f->carro[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nCarro nao encontrado para manobra.\n");
        return;
    }

    //Copia todos os carros antes do carro a ser removido para aux
    for (i = f->inicio; i < pos; i++) {
        aux[auxCount] = f->carro[i];
        aux[auxCount].manobras++;
        auxCount++;
    }

    printf("\nCarro %d saiu do estacionamento com um total de %d manobras\n", f->carro[pos].id, f->carro[pos].manobras);

    //Deslocando os carros restantes para a esquerda na fila principal
    for (i = pos + 1, j = f->inicio; i <= f->fim; i++, j++) {
        f->carro[j] = f->carro[i];
    }

    //Atualizando os índices
    f->fim = f->fim - (pos - f->inicio + 1); 
    f->inicio = 0;

    //Reinserindo os carros 
    for (i = 0; i < auxCount; i++) {
        f->fim++;
        f->carro[f->fim] = aux[i];
    }
}

void remover(fila *f){
    if(f->inicio > f->fim){
        printf("\nO estacionamento esta vazio\n");
    }else{
        printf("\nCarro %d saiu do estacionamento com um total de %d manobras\n", f->carro[f->inicio].id, f->carro[f->inicio].manobras);
        f->inicio++;
    }
}

void exibirEstacionamento(fila *f){
    int i;
    printf("\nFila do Estacionamento");
    printf("\n===================================\n");
    for(i = f->inicio; i <= f->fim; i++){
        printf(" %d", f->carro[i].id);
    }
    printf("\n===================================\n");
}

int main(){
    fila f;
    inicializa(&f);
    int opc = 111, id;
    do{
        printf("\nMenu\n0 - Sair\n1 - Adicionar carro ao estacionamento\n2 - Retirar carro do estacionamento\n3 - Exibir fila de carros no estacionamento\n");
        scanf("%d", &opc);
        switch(opc){
            case 0: 
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("\nDigite o ID do carro: ");
                scanf("%d", &id);
                adicionar(&f, id);
                break;
            case 2:
                printf("\nDigite o ID do carro a ser removido: ");
                scanf("%d", &id);
                if(existe(&f, id)){
                    if(verificaPosicao(&f, id)){
                        remover(&f);
                    }else{
                        manobra(&f, id);
                    }
                }else{
                    printf("\nID inexistente!");
                }
                break;
            case 3:
                exibirEstacionamento(&f);
                break;
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }while(opc != 0);
    return 0;
}