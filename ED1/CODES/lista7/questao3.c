/* Faça um algoritmo que inverta uma lista encadeada, isto é, o último elemento passa a ser o primeiro, o penúltimo passa a ser o segundo, e assim por diante, e o primeiro passa a ser o último. Faça a inversão através da inversão dos campos de ligação, e NÃO dos campos de informação. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int item;
    struct Lista *proximo;
} *lista;

void exibir(lista l){
    lista aux = l;
    printf("\n\tLista\n");
    if(aux == NULL){
        printf("\nLista vazia");
    }
    while(aux != NULL){
        printf("\nItem %d", aux->item);
        aux = aux->proximo;
    }
    printf("\n");
}

lista criarItem(int item){
    lista novo = (lista) malloc(sizeof(struct Lista));
    if(novo == NULL){
        return NULL;
    }
    novo->item = item;
    novo->proximo = NULL;
    return novo;
}

lista inserir(lista l, int item){
    lista novo = criarItem(item);
    if(novo == NULL){
        return l;
    }else if(l == NULL){
        return novo;
    }else{
        lista aux = l;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
        printf("\nItem %d inserido\n", novo->item);
        return l;
    }
}

lista inverter(lista l){
    lista novo = NULL;
    lista atual = l;
    lista proximo = NULL;
    while(atual != NULL){
        proximo = atual->proximo;
        atual->proximo = novo;
        novo = atual;
        atual = proximo;
    }
    return novo;
}

int main(){
    lista lista1 = NULL;
    int opc = 333, num;
    do{
        printf("\n\tMenu\n0 - Sair\n1 - Inserir registro\n2 - Inverter lista\n3 - Exibir\n");
        printf("\nInsira a opcao desejada: ");
        scanf("%d", &opc);
        switch (opc){
        case 0:
            printf("\nSaindo...");
            break;

        case 1:            
            printf("\nInsira um numero: ");
            scanf("%d", &num);
            lista1 = inserir(lista1, num);
            break;

        case 2:
            lista1 = inverter(lista1);
            break;

        case 3:
            exibir(lista1);
            break;

        default:
            printf("\nOpcao invalida");
            break;
        }
    }while(opc != 0);
    free(lista1);
    return 0;
}