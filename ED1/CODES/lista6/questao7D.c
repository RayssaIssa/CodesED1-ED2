/*Suponha um estacionamento que guarda até 7 carros. Os carros entram pela rua A e saem pela rua B. Se chegar um cliente para retirar um carro que não esteja estacionado na primeira vaga da rua B, todos os carros entre o carro do cliente e a rua B serão deslocados para fora do estacionamento, o carro do  cliente sairá do estacionamento e os outros carros voltarão a entrar pela entrada A na mesma ordem que saíram pela rua B. Observe que sempre que um carro deixa o estacionamento, todos os carros entre ele e a entrada A serão deslocados até o começo da rua B (da saída) de modo que, o tempo inteiro, todos os espaços vazios estão na entrada do estacionamento, ou seja na entrada pela rua A. 
Escreva um programa que simule o funcionamento deste estacionamento, usando a estrutura de dados adequada. O seu programa deve receber do usuário um número identificador de cada carro. O programa deve imprimir uma mensagem sempre que um carro chegar ou sair. Quando um carro chegar, a mensagem deve especificar se existe ou não vaga para o carro no estacionamento. Se não houver vaga, o carro não será inserido. Quando um carro sair do estacionamento, a mensagem deverá incluir o número de vezes em que o carro foi manobrado para fora do estacionamento para permitir que os outros carros saíssem*/

#include <stdio.h>
#include <stdlib.h>

struct Carro{
    int id;
    int manobras;
};

typedef struct estacionamento{
    struct Carro carro;
    struct estacionamento *prox;
} *fila;

fila criarItem(int id){
    fila novo = (fila) malloc(sizeof(struct estacionamento));
    if(novo == NULL){
        printf("\nNao foi possivel alocar memoria\n");
        return NULL;
    }
    novo->carro.id = id;
    novo->carro.manobras = 0;
    novo->prox = NULL;
    return novo;
}

fila adicionar(fila f, int id){
    fila novo = criarItem(id);
    if(novo == NULL){
        return f;
    }else if(f == NULL){
        printf("\nCarro %d foi adicionado ao estacionamento\n", id);
        return novo;
    }else{
        fila aux = f;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        printf("\nCarro %d foi adicionado ao estacionamento\n", id);
        return f;
    }
}

int existe(fila f, int id){
    if(f == NULL){
        printf("\nO estacionamento esta vazio\n");
        return 0;
    }
    fila aux = f;
    while(aux != NULL){
        if(aux->carro.id == id){
            return 1;
        }else{
            aux = aux->prox;
        }
    }
    return 0;
}

int verificaPosicao(fila f, int id){
    if(f->carro.id == id){
        return 1;
    }else{
        return 0;
    }
}

fila manobra(fila f, int id) {
    fila aux = f;
    fila filaTemporario = NULL;
    fila fimTemporaria = NULL;
    int encontrou = 0;

    // Percorre até encontrar o carro
    while(aux != NULL){
        if(aux->carro.id == id){
            encontrou = 1;
            break;
        }

        // Remove o carro da frente e coloca na filaTemporario com manobra++
        fila novo = criarItem(aux->carro.id);
        novo->carro.manobras = aux->carro.manobras + 1;

        if(filaTemporario == NULL){
            filaTemporario = fimTemporaria = novo;
        } else {
            fimTemporaria->prox = novo;
            fimTemporaria = novo;
        }

        // Remove o carro da frente da fila principal
        fila removido = f;
        f = f->prox;
        free(removido);
        aux = f;
    }

    // Carro encontrado remove 
    printf("\nCarro %d saiu do estacionamento com um total de %d manobras\n", aux->carro.id, aux->carro.manobras);
    f = f->prox;
    free(aux);

    // Coloca todos os que foram manobrados de volta no fim
    if(f == NULL){
        return filaTemporario;
    } else {
        fila fim = f;
        while(fim->prox != NULL){
            fim = fim->prox;
        }
        fim->prox = filaTemporario;
        return f;
    }
}

fila remover(fila f){
    if(f == NULL){
        printf("\nO estacionamento esta vazio\n");
        return f;
    }
    fila auxiliar = f;
    printf("\nCarro %d saiu do estacionamento com um total de %d manobras\n", auxiliar->carro.id, auxiliar->carro.manobras);
    f = f->prox;
    free(auxiliar);
    auxiliar = NULL;
    return f;
}

void exibirEstacionamento(fila f){
    fila aux = f;
    printf("\nFila do Estacionamento");
    printf("\n===================================\n");
    while(aux != NULL){
        printf(" %d", aux->carro.id);
        aux = aux->prox;
    }
    printf("\n===================================\n");
}

int main(){
    fila f = NULL;
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
                f = adicionar(f, id);
                break;
            case 2:
                printf("\nDigite o ID do carro a ser removido: ");
                scanf("%d", &id);
                if(existe(f, id)){
                    if(verificaPosicao(f, id)){
                        f = remover(f);
                    }else{
                        f = manobra(f, id);
                    }
                }else{
                    printf("\nID inexistente!");
                }
                break;
            case 3:
                exibirEstacionamento(f);
                break;
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }while(opc != 0);
    free(f);
    return 0;
}