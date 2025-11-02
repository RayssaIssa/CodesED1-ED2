/* Faça um programa em C que concatene duas listas, dando origem a uma única lista com uma ponteiro “Terc” apontando seu primeiro elemento.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int num;
    struct Lista *proximo;
} *lista;

void exibir(lista l){
    lista aux = l;
    if(aux == NULL){
        printf("\nLista vazia\n");
        return;
    }
    printf("\n");
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
    return novo;
}

lista inserir(lista l, int num){
    lista novo = criarItem(num);
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
        return l;
    }
}

lista concatenarListas(lista um, lista dois){
    if(um == NULL || dois == NULL){
        printf("\nUma ou mais listas vazia\n");
        return NULL;
    }
    lista tres = NULL;
    tres = um;
    lista aux3 = tres;
    while(aux3->proximo != NULL){
        aux3 = aux3->proximo;
    }
    aux3->proximo = dois;
    return tres;
}

int main(){
    lista prim = NULL;
    lista sec = NULL;
    lista terc = NULL;

    int opc = 333, num;
    do{
        printf("\n\tMenu\n0 - Sair\n1 - Inserir numero na lista Prim\n2 - Inserir numero na lista Sec\n3 - Concatenar listas\n4 - Exibir listas");
        printf("\nInsira a opcao desejada: ");
        scanf("%d", &opc);
        switch (opc){
        case 0:
            printf("\nSaindo...");
            break;

        case 1:            
            printf("\nInsira um numero: ");
            scanf("%d", &num);
            prim = inserir(prim, num);
            break;

        case 2:
            printf("\nInsira um numero: ");
            scanf("%d", &num);
            sec = inserir(sec, num);
            break;

        case 3:
            terc = concatenarListas(prim, sec);
            break;

        case 4:
            printf("\nQual lista deseja exibir? \n1 - Prim\n2 - Sec\n3 - Terc\n");
            scanf("%d", &opc);

            switch (opc){
            case 1:
                printf("\n\tLista Prim\n");
                exibir(prim);                
                break;
            case 2:
                printf("\n\tLista Sec\n");
                exibir(sec);
                break;
            case 3:
            printf("\n\tLista 'Terc'\n");
                exibir(terc);
                break;
            default:
                printf("\nOpcao invalida");
                break;
            }
            break;

        default:
            printf("\nOpcao invalida");
            break;
        }
    }while(opc != 0);

    free(prim);
    free(sec);
    free(terc);
    return 0;
}