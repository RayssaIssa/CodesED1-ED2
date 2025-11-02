#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int item;
    struct no *proximo;
    struct no *anterior;
} *lista;

void exibir(lista l){
    lista aux = l;
    printf("\n\tLista Duplamente encadeada\n");
    while(aux != NULL){
        printf("[%d] ", aux->item);
        aux = aux->proximo;
    }
    printf("\n");
}

lista criarNo(int valor){
    lista novo = (lista) malloc(sizeof(struct no));
    if(novo == NULL){
        printf("\nErro ao alocar memoria\n");
        return NULL;
    }
    novo->item = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}

int existeValor(lista l, int num){
    lista aux = l;
    do{
        if(aux->item == num){
            return 1;
        }
        aux = aux->proximo;
    }while(aux != NULL);
    return 0;
}

lista removerNaEsquerda(lista l){
    lista aux = l->proximo;
    if (aux != NULL) { 
        aux->anterior = NULL;
    }
    free(l);
    l = NULL;
    return aux;
}

lista removerNoMeio(lista l, int valor){
	lista aux = l;
	while(aux != NULL){
		if(aux->proximo->item == valor){
			lista remover = aux->proximo;
			lista daFrente = aux->proximo->proximo;
			aux->proximo = daFrente;
			daFrente->anterior = aux;
			free(remover);
			remover = NULL;
			return l;
		}else{
			aux = aux->proximo;
		}
	}
}

lista removerNaDireita(lista l){
    lista aux = l;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->anterior->proximo = NULL;
    free(aux);
    aux = NULL;
    return l;
}

lista removerOnde(lista l){
    printf("\nOnde deseja remover o valor?\n1 - Inicio\n2 - Fim\n3 - Meio\n");
    int opc;
    scanf("%d", &opc);
    lista retorno = NULL;
    switch (opc){
        case 1:
            retorno = removerNaEsquerda(l);
            return retorno;
            break;

        case 2:
            retorno = removerNaDireita(l);
            return retorno;
            break;

        case 3:
            exibir(l);
            printf("\nDeseja remover qual valor? ");
            int num;
            scanf("%d", &num);
            if(existeValor(l, num)){
                retorno = removerNoMeio(l, num);
                return retorno;
            }else{
                printf("\nValor inexistente na lista\n");
                return l;
            }
            break;

        default:
            printf("\nValor invalido\n");
            break;
    }
    return l;
}

lista remover(lista l){
    if(l == NULL){
        printf("\nLista vazia\n");
        return l;
    }
    if(l->proximo == NULL){
        free(l);
        l = NULL;
        return l;
    }
    lista remover = removerOnde(l);
    return remover;
}

lista adicionarNaEsquerda(lista l, lista novo){
    l->anterior = novo;
    novo->proximo = l;
    return novo;
}

lista adicionarNoMeio(lista l, lista novo, int valor){
    lista aux = l;
    while(aux->item != valor){
        aux = aux->proximo;
    }
    lista auxFrente = aux->proximo;
    novo->anterior = aux;
    novo->proximo = auxFrente;
    aux->proximo = novo;
    if (auxFrente != NULL) { 
        auxFrente->anterior = novo;
    }
    return l;
}

lista adicionarNaDireita(lista l, lista novo){
    lista aux = l;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo;
    novo->anterior = aux;
    return l;
}

lista adicionarOnde(lista l, lista novo){
    printf("\nOnde deseja adicionar o valor?\n1 - Inicio\n2 - Fim\n3 - Meio\n");
    int opc;
    scanf("%d", &opc);
    lista retorno = NULL;
    switch (opc){
        case 1:
            retorno = adicionarNaEsquerda(l, novo);
            return retorno;
            break;

        case 2:
            retorno = adicionarNaDireita(l, novo);
            return retorno;
            break;

        case 3:
            exibir(l);
            printf("\nDeseja inserir depois de qual valor? ");
            int num;
            scanf("%d", &num);
            if(existeValor(l, num)){
                retorno = adicionarNoMeio(l, novo, num);
                return retorno;
            }else{
                printf("\nO valor nao existe na lista\n");
                return l;
            }
            break;

        default:
            printf("\nValor invalido\n");
            break;
    }
    return l;
}

lista adicionar(lista l, int valor){
    lista novo = criarNo(valor);
    if(novo == NULL){
        return l;
    }if(l == NULL){
        return novo;
    }
    lista retornar = adicionarOnde(l, novo);
    return retornar;
}

int main(){
    lista l1 = NULL;
    int opc = 333;
    do{
        printf("\n\tMenu\n0 - Sair\n1 - Adicionar item na lista\n2 - Remover item da lista\n");
        scanf("%d", &opc);
        switch (opc){
            case 0:
                printf("\nSaindo...\n");
                break;

            case 1:
                printf("\nDigite o valor que deseja adicionar: ");
                int valor;
                scanf("%d", &valor);
                l1 = adicionar(l1, valor);
                exibir(l1);
                break;

            case 2: 
                exibir(l1);
                l1 = remover(l1);
                exibir(l1);
                break;
                
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }while(opc != 0);
    return 0;
}