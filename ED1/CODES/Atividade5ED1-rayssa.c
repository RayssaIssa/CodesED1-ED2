#include <stdio.h>
#include <stdlib.h>

typedef struct ITEM{
    int item;
    struct ITEM *prox;
} *Fila;

Fila criaItem(int valor){
    Fila novo = (Fila) malloc(sizeof(Fila));
    if(novo == NULL){
        printf("\nErro ao alocar memoria");
        return NULL;
    }
    novo->item = valor;
    novo->prox = NULL;
    return novo;
}

Fila inserir(Fila f, int valor){
    Fila novo = criaItem(valor);
    if(f == NULL){
        return novo;
    }else{
        Fila aux = f;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        printf("\nItem %d inserido\n", novo->item);
        return f;
    }
}

Fila remover(Fila f){
    if(f == NULL){
        printf("\nFila vazia");
        return NULL;
    }
    printf("\nItem %d removido\n", f->item);
    Fila aux = f;
    f = f->prox;
    free(aux);
    aux = NULL;
    return f;
}

void consultaFila(Fila f){
    Fila aux = f;
    printf("\n\tFila atual\n");
    while(aux != NULL){
        printf(" [%d]", aux->item);
        aux = aux->prox;
    }
}

int main(){
    Fila fila = NULL;

    int opc = 11;
    do{
        printf("\n\tMenu\n0- Sair\n1- Inserir elemento na fila\n2- Remover elemento da fila\n");
        printf("Insira sua opcao: ");
        scanf("%d", &opc);

        switch (opc){
            case 0:
                printf("\nSaindo...");
                break;

            case 1:
                printf("\nInsira o elemento para inserir: ");
                int elemento;
                scanf("%d", &elemento);
                fila = inserir(fila, elemento);
                consultaFila(fila);
                break;

            case 2:
                fila = remover(fila);
                consultaFila(fila);
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
    }while (opc != 0);  

    free(fila);
    return 0;
}