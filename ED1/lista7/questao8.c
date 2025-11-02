/*Escreva uma função void MoveMenor(TipoLista Lista) que, dada uma lista duplamente encadeada com um número qualquer de elementos, acha o menor elemento da lista e o move para o começo da lista. (Obs. Não vale trocar apenas os campos item ou usar uma lista / fila / pilha auxiliar! Você deverá fazer a manipulação dos ponteiros para trocar as células de posição). */
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int num;
    struct Lista *proximo;
    struct Lista *anterior;
} *lista;

void exibir(lista l){
    lista aux = l;
    if(aux == NULL){
        printf("\nLista vazia\n");
        return;
    }
    printf("\n\tLista\n");
    while(aux != NULL){
        printf("[%d] -> ", aux->num);
        aux = aux->proximo;
    }
    printf("NULL\n");
}

lista criarItem(int num){
    lista novo = (lista) malloc(sizeof(struct Lista));
    if(novo == NULL){
        return NULL;
    }
    novo->num = num;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}

int existe(lista l, int k){
    lista aux = l;
    if(aux == NULL){
        return 0;
    }else{
        while(aux != NULL){
            if(aux->num == k){
                return 1;
            }
            aux = aux->proximo;
        }
        return 0;
    }
}

lista inserir(lista l, int num){
    lista novo = criarItem(num);
    if(novo == NULL){
        printf("\nNao foi possivel alocar memoria");
        return l;
    }else if(l == NULL){
        return novo;
    }else{
        lista aux = l;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        novo->anterior = aux;
        aux->proximo = novo;
        printf("\nNumero %d inserido\n", num);
        return l;
    }
}

lista MoveMenor(lista l){
    if(l == NULL || l->proximo == NULL){
        return l;
    }
    lista aux = l;
    lista menor = aux->proximo;
    //Encontra o menor
    while(aux != NULL){
        if(aux->num < menor->num){
            menor = aux;
        }
        aux = aux->proximo;
    }
    //Verifica se ele já esta no inicio
    if(menor == l){
        return l;
    }else{
        if(menor->anterior != NULL){
            menor->anterior->proximo = menor->proximo;
        }
        if(menor->proximo != NULL){
            menor->proximo->anterior = menor->anterior;
        }
        menor->proximo = l;
        menor->anterior = NULL;
        l->anterior = menor;
        return menor;
    }
}

int main(){
    lista L = NULL;
    int opc = 333, numero;
    do{
        printf("\n\tMenu\n0 - Sair\n1 - Inserir numero\n2 - Exibir lista\n");
        printf("\nInsira a opcao desejada: ");
        scanf("%d", &opc);
        switch (opc){
            case 0:
                printf("\nSaindo...");
                break;

            case 1:            
                printf("\nNumero a inserir: ");
                scanf("%d", &numero);
                L = inserir(L, numero);
                L = MoveMenor(L);
                break;

            case 2:
                exibir(L);
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(opc != 0);

    free(L);
    return 0;
}