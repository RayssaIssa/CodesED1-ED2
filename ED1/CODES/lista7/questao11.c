/*Dada uma lista encadeada que armazena números inteiros escreva uma função que transforma a lista dada em duas listas encadeadas: a primeira contendo os elementos cujo conteúdo é par e a segunda contendo os elementos com conteúdos impares. Sua função deve manipular somente os apontadores e não o conteúdo das células. */

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

lista adiciona(lista *destino, lista elemento){
    elemento->proximo = NULL;
    if(*destino == NULL){
        return elemento;
    }else{
        lista auxD = *destino;
        while(auxD->proximo != NULL){
            auxD = auxD->proximo;
        }
        auxD->proximo = elemento;
        return *destino;
    }
}

void separarLista(lista original, lista *impar, lista *par){
    if(original == NULL){
        printf("\nLista vazia\n");
        return;
    }else{
        *impar = NULL;
        *par = NULL;
        lista aux = original;
        lista anterior = NULL;
        while(aux != NULL){
            lista proximo = aux->proximo;
            if(aux->num % 2 == 0){
                if(anterior == NULL){
                    original = proximo;
                }else{
                    anterior->proximo = proximo;
                }
                
                *par = adiciona(par, aux);
            }else{
                if(anterior == NULL){
                    original = proximo;
                }else{
                    anterior->proximo = proximo;
                }
                *impar = adiciona(impar, aux);
            }
            aux = proximo;
        }
    }
}

int main(){
    lista inicial = NULL;
    lista copiaInicial = NULL;
    lista impar = NULL;
    lista par = NULL;

    int opc = 333, num;
    do{
        printf("\n\tMenu\n0 - Sair\n1 - Inserir numero na lista Inicial\n2 - Dividir lista em Impar e Par\n3 - Exibir listas");
        printf("\nInsira a opcao desejada: ");
        scanf("%d", &opc);
        switch (opc){
            case 0:
                printf("\nSaindo...");
                break;

            case 1:            
                printf("\nInsira um numero: ");
                scanf("%d", &num);
                inicial = inserir(inicial, num);
                copiaInicial = inserir(copiaInicial, num);
                break;

            case 2:
                separarLista(inicial, &impar, &par);
                inicial = copiaInicial;
                break;

            case 3:
                printf("\nQual lista deseja exibir? \n1 - Inicial\n2 - Impar\n3 - Par\n");
                scanf("%d", &opc);

                switch (opc){
                    case 1:
                        printf("\n\tLista inicial\n");
                        exibir(copiaInicial);                
                        break;
                    case 2:
                        printf("\n\tLista impar\n");
                        exibir(impar);
                        break;
                    case 3:
                        printf("\n\tLista Par\n");
                        exibir(par);
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

    free(inicial);
    free(copiaInicial);
    free(impar);
    free(par);
    return 0;
}