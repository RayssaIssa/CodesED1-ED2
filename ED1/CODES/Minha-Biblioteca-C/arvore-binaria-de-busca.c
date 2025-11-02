#include <stdio.h>
#include <stdlib.h>

typedef struct ITEM{
    int raiz;
    struct ITEM *esquerda;
    struct ITEM *direita;
} *Arvore;

Arvore criarNoh(int n){
    Arvore novo = (Arvore) malloc(sizeof(struct ITEM));
    if(novo == NULL){
        exit(1);
    }
    novo->raiz = n;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

Arvore inserir(Arvore a, int n){
    if(a == NULL){
        return criarNoh(n);
    }else{
        if(n > a->raiz){
            a->direita = inserir(a->direita, n);
        }else{
            a->esquerda = inserir(a->esquerda, n);
        }
    }
    return a;
}

Arvore encontrarMenor(Arvore a) {
    while(a->esquerda != NULL) {
        a = a->esquerda;
    }
    return a;
}

Arvore remover(Arvore a, int valor){
    if (a == NULL) return NULL;

    if (valor < a->raiz) {
        a->esquerda = remover(a->esquerda, valor);
    } else if (valor > a->raiz) {
        a->direita = remover(a->direita, valor);
    } else {

        if (a->esquerda == NULL && a->direita == NULL) {
            free(a);
            return NULL;
        } else if (a->esquerda == NULL) {
            Arvore temp = a->direita;
            free(a);
            return temp;
        } else if (a->direita == NULL) {
            Arvore temp = a->esquerda;
            free(a);
            return temp;
        }
        Arvore temp = encontrarMenor(a->direita);
        a->raiz = temp->raiz;
        a->direita = remover(a->direita, temp->raiz);
    }
    return a;
}

Arvore buscar(Arvore a, int valor) {
    if (a == NULL) {
        return NULL;
    }
    if (valor == a->raiz) {
        return a;
    } else if (valor < a->raiz) {
        return buscar(a->esquerda, valor);
    } else {
        return buscar(a->direita, valor);
    }
}

void exibirPreOrdem(Arvore arv){
    if (arv != NULL) {
        printf("%d ", arv->raiz);
        exibirPreOrdem(arv->esquerda);
        exibirPreOrdem(arv->direita);
    }
}

void exibirInOrdem(Arvore arv){
    if (arv != NULL) {
        exibirInOrdem(arv->esquerda);
        printf("%d ", arv->raiz);
        exibirInOrdem(arv->direita);
    }
}

void exibirPosOrdem(Arvore arv){
    if (arv != NULL) {
        exibirPosOrdem(arv->esquerda);
        exibirPosOrdem(arv->direita);
        printf("%d ", arv->raiz);
    }
}

int main(){
    Arvore arv = NULL;
    int valor, opc = 333;

    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Exibir Pre-Ordem\n4 - Exibir In-Ordem\n5 - Exibir Pos-Ordem\n6 - Buscar\n\nSua opcao e: ");
        scanf("%d", &opc);
        switch(opc){
            case 0:
                printf("\nSaindo\n");
                break;
            case 1:
                printf("\nQual valor deseja inserir? ");
                scanf("%d", &valor);
                arv = inserir(arv, valor);
                break;

            case 2:
                printf("\nQual valor deseja remover? ");
                scanf("%d", &valor);
                arv = remover(arv, valor);
                break;

            case 3:
                printf("\n");
                exibirPreOrdem(arv);
                printf("\n");
                break;

            case 4:
                printf("\n");
                exibirInOrdem(arv);
                printf("\n");
                break;

            case 5:
                printf("\n");
                exibirPosOrdem(arv);
                printf("\n");
                break;

            case 6:
                printf("\nQual valor deseja buscar? ");
                scanf("%d", &valor);

                Arvore resultado = buscar(arv, valor);
                if (resultado != NULL) {
                    printf("\nValor %d encontrado!\n", resultado->raiz);
                } else {
                    printf("\nValor %d nao encontrado\n", valor);
                }
                break;

            default:
                printf("\nValor invalido");
                break;
        }
    }while(opc != 0);

    free(arv);
    return 0;
}