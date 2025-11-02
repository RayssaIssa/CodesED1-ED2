#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int inicio;
    int fim;
    int elementos[5];
} Fila;

void inicializaFila(Fila *f){
    f->fim = -1;
    f->inicio = 0;
}

int filaVazia(Fila *f){
   if(f->inicio > f->fim){
        return 1;
   }else{
        return 0;
   }
}

int filaCheia(Fila *f){
    if(f->fim == 4){
        return 1;
    }else{
        return 0;
    }
}

void inserir(Fila *f, int n){
    if(filaCheia(f)){
        printf("\nFila cheia\n");
        return;
    }
    f->fim++;
    f->elementos[f->fim] = n;
    printf("\nElemento %d inserido\n", n);
}

void remover(Fila *f){
    if(filaVazia(f)){
        printf("\nNao ha mais itens na fila\n");
    }else{
        int removido = f->elementos[f->inicio];
        f->inicio++;
        printf("\nElemento %d removido", removido);
    }
}

void consultaFila(Fila *f){
    printf("\nO inicio da fila: %d\tO fim da fila: %d\n", f->inicio, f->fim);
}

int main(){
    Fila *fila;
    fila = malloc(sizeof(Fila));
    if(fila == NULL){
        printf("\nNao foi possivel alocar memoria");
        return 1;
    }

    inicializaFila(fila);
    consultaFila(fila);

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
                inserir(fila, elemento);
                consultaFila(fila);
                break;

            case 2:
                remover(fila);
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