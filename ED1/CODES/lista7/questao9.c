/*Seja L uma lista duplamente encadeada que armazena registros de um arquivo. Implemente em linguagem C as seguintes funções: 
a) função numero(L) – retorna o número de elementos da lista L. 
b) função troca(K, L, v) – modifica o elemento K da lista para v. 
c) função insereEsq(K, L, v) – insere o valor v a esquerda do elemento K. 
d) função insereDir(K, L, v) – insere o valor v a direita do elemento K. 
e) função banir(L,v) – elimina todas as ocorrências do elemento v da lista L. */
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

void numero(lista l){
    lista aux = l;
    int quantidade = 0;
    while(aux != NULL){
        quantidade++;
        aux = aux->proximo;
    }
    printf("\nO numero de elementos da lista e: %d\n", quantidade);
}

lista troca(int k, lista l, int v){
    lista aux = l;
    while(aux->num != k){
        aux = aux->proximo;
    }
    aux->num = v;
    return l;
}

lista insereDir(int k, lista l, int v){
    lista novo = criarItem(v);
    if(novo == NULL){
        return l;
    }else{
        lista aux = l;
        while(aux->num != k){
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        novo->anterior = aux;
        aux->proximo = novo;
        return l;
    }
}

lista insereEsq(int k, lista l, int v){
    lista novo = criarItem(v);
    if(novo == NULL){
        return l;
    }else{
        if(l->num == k){
            novo->proximo = l;
            return novo;
        }
        lista aux = l;
        while(aux->proximo->num != k){
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        novo->anterior = aux;
        aux->proximo = novo;
        return l;
    }
}

lista banir(lista l, int v){
    while(l != NULL && l->num == v) {
        lista remover = l;
        l = l->proximo;
        l->anterior = NULL;
        free(remover);
        remover = NULL;
    }
    
    if(l == NULL){
        return NULL;
    }
    
    lista aux = l;
    while(aux->proximo != NULL){
        if(aux->proximo->num == v){
            lista remover = aux->proximo;
            aux->proximo = aux->proximo->proximo;
            free(remover);
            remover = NULL;
        }else{
            aux = aux->proximo;
        }
    }
    return l;
}

int main(){
    lista L = NULL;

    int opc = 333, K, v;
    do{
        printf("\n\tMenu\n0 - Sair\n1 - (A)Retornar o numero de elementos da lista L\n2 - (B)Modificar elemento K da lista para V\n3 - (C)Inserir valor V a esquerda do elemento K\n4 - (D)Inserir valor V a direita do elemento K\n5 - (E)Eliminar todas as ocorrencias do elemento V da lista L\n6 - Exibir lista L\n");
        printf("\nInsira a opcao desejada: ");
        scanf("%d", &opc);
        switch (opc){
            case 0:
                printf("\nSaindo...");
                break;

            case 1:            
                printf("\n(A)Retornar o numero de elementos da lista L\n");
                numero(L);
                break;

            case 2:
                printf("\n(B)Modificar elemento K da lista para V\n");
                printf("Qual elemento deseja modificar? ");
                scanf("%d", &K);
                if(existe(L, K)){
                    printf("\nPor qual valor deseja alterar o %d? ", K);
                    scanf("%d", &v);
                    L = troca(K, L, v);
                }else{
                    printf("\nO elemento inserido nao existe.\n");
                }
                break;

            case 3:
                printf("\n(C)Inserir valor V a esquerda do elemento K\n");
                if(L == NULL){
                    printf("\nPrimeiro elemento\nQual valor deseja inserir? ");
                    scanf("%d", &v);
                    L = criarItem(v);
                }else{
                    printf("\nA insercao deve ser a esquerda de qual elemento? ");
                    scanf("%d", &K);
                    if(existe(L, K)){
                        printf("Qual valor deseja inserir? ");
                        scanf("%d", &v);
                        L = insereEsq(K, L, v);
                    }else{
                        printf("\nO elemento inserido nao existe.\n");
                    }
                }
                break;

            case 4:
                printf("\n(D)Inserir valor V a direita do elemento K\n");
                if(L == NULL){
                    printf("\nPrimeiro elemento\nQual valor deseja inserir? ");
                    scanf("%d", &v);
                    L = criarItem(v);
                }else{
                    printf("\nA insercao deve ser a direita de qual elemento? ");
                    scanf("%d", &K);
                    if(existe(L, K)){
                        printf("Qual valor deseja inserir? ");
                        scanf("%d", &v);
                        L = insereDir(K, L, v);
                    }else{
                        printf("\nO elemento inserido nao existe.\n");
                    }
                }
                break;

            case 5:
                printf("\n(E)Eliminar todas as ocorrencias do elemento V da lista L\n");
                printf("Qual elemento deve ser eliminado? ");
                scanf("%d", &v);
                if(existe(L, v)){                    
                    L = banir(L, v);
                }else{
                    printf("\nO elemento inserido nao existe.\n");
                }
                break;

            case 6:
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