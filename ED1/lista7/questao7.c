/*Dada uma lista encadeada que armazena números inteiros escreva uma função que transforma a lista dada em duas listas encadeadas: a primeira contendo os elementos cujo conteúdo são números primos e a segunda contendo os elementos com conteúdos que não são números primos. Sua função deve manipular somente os ponteiros e não o conteúdo das células.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA{
    int numero;
    struct LISTA *proximo;
} *lista;

void exibir(lista l){
    lista aux = l;
    printf("\n");
    if(aux == NULL){
        printf("\nLista vazia\n");
    }
    while(aux != NULL){
        printf(" [%d]", aux->numero);
        aux = aux->proximo;
    }
    printf("\n");
}

lista criarItem(int numero){
    lista novo = (lista) malloc(sizeof(struct LISTA));
    if(novo == NULL){
        return NULL;
    }
    novo->numero = numero;
    novo->proximo = NULL;
    return novo;
}

lista inserir(lista l, int numero){
    lista novo = criarItem(numero);
    if(novo == NULL){
        return l;
    }else if(l == NULL){
        return novo;
    }
    lista aux = l;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo;
    return l;
}

int ehPrimo(int n){
    if(n <= 1){
        return 0;  
    }else if(n == 2){
        return 1; 
    }else if(n % 2 == 0){
        return 0; 
    }
    int i;
    for(i = 3; i * i <= n; i += 2){  
        if(n % i == 0){
            return 0;  
        }
    }
    return 1;
}

lista adicionaElemento(lista *destino, lista elemento){
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

void separaPrimos(lista original, lista *primos, lista *naoPrimos){
    if(original == NULL){
        return;
    }else{
        *primos = NULL;
        *naoPrimos = NULL;
        
        lista aux = original;
        lista anterior = NULL;
        while(aux != NULL){
            lista proximo = aux->proximo;

            if(ehPrimo(aux->numero)){
                if(anterior == NULL){
                    original = proximo;
                }else{
                    anterior->proximo = proximo;
                }
                *primos = adicionaElemento(primos, aux);
            }else{
                if(anterior == NULL){
                    original = proximo;
                }else{
                    anterior->proximo = proximo;
                }
                *naoPrimos = adicionaElemento(naoPrimos, aux);
            }

            aux = proximo;
        }
    }
}

int main(){
    lista original = NULL;
    lista copiaOriginal = NULL;
    lista primos = NULL;
    lista naoPrimos = NULL;

    int opc = 333, num;
    do{
        printf("\n\tMenu\n0 - Sair\n1 - Inserir numero\n2 - Separar Numeros primos e nao primos\n3 - Exibir\n");
        printf("\nInsira a opcao desejada: ");
        scanf("%d", &opc);

        switch (opc){
        case 0:
            printf("\nSaindo...");
            break;

        case 1:            
            printf("\nInsira um numero: ");
            scanf("%d", &num);
            original = inserir(original, num);
            copiaOriginal = inserir(copiaOriginal, num);
            break;

        case 2:
            separaPrimos(original, &primos, &naoPrimos);
            original = copiaOriginal;   //Re-salvando o original, após uma segunda separação de primos ele será perdido

            printf("\n\tLista dos numeros Primos\n");
            exibir(primos);
            printf("\n\tLista dos numeros nao primos\n");
            exibir(naoPrimos);
            break;

        case 3:
            printf("\nQual lista deseja exibir? \n1 - Original\n2 - Primos\n3 - Nao Primos\n");
            scanf("%d", &opc);

            switch (opc){
            case 1:
                printf("\n\tLista original\n");
                exibir(copiaOriginal);                
                break;
            case 2:
                printf("\n\tLista dos numeros Primos\n");
                exibir(primos);
                break;
            case 3:
                printf("\n\tLista dos numeros nao primos\n");
                exibir(naoPrimos);
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

    free(original);
    free(copiaOriginal);
    free(primos);
    free(naoPrimos);

    return 0;
}