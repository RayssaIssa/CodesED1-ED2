#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    struct arvore *esquerda;
    struct arvore *direita;
    int valor;
    int altura;
} *noh;

int tamanhoDoEspaco = 10;

void exibir(noh raiz, int espaco) {
    if (raiz == NULL){
        return;
    }
    espaco += tamanhoDoEspaco;
    exibir(raiz->direita, espaco);
    printf("\n");
    for (int i = tamanhoDoEspaco; i < espaco; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->valor);
    exibir(raiz->esquerda, espaco);
}

void destruir(noh raiz){
    if (raiz != NULL) {
        destruir(raiz->esquerda);
        destruir(raiz->direita);
        free(raiz);
    }
}

int alturaNoh(noh raiz) {
    if (raiz == NULL) {
        return -1;
    }
    return raiz->altura;
}

int fatorBalanceamento(noh raiz){
    if (raiz == NULL) {
        return 0;
    }
    return alturaNoh(raiz->esquerda) - alturaNoh(raiz->direita);
}

int maior(int x, int y){
    if (x > y){
        return x;
    }
    return y;
}

int alturaArvore(noh raiz){
    int alturaDireita = 0, alturaEsquerda = 0;

    if (raiz == NULL){
        return -1;
    }
    alturaEsquerda = alturaArvore(raiz->esquerda);
    alturaDireita = alturaArvore(raiz->direita);

    if (alturaEsquerda > alturaDireita){
        return alturaEsquerda + 1;
    }
    return alturaDireita + 1;
}

int contarNos(noh raiz){
    if (raiz == NULL){
        return 0;
    }
    return contarNos(raiz->esquerda) + contarNos(raiz->direita) + 1;
}

noh rotacaoDireita(noh raiz) {
    noh aux = raiz->esquerda;
    noh T2 = aux->direita;

    aux->direita = raiz;
    raiz->esquerda = T2;

    raiz->altura = maior(alturaNoh(raiz->esquerda), alturaNoh(raiz->direita)) + 1;
    aux->altura = maior(alturaNoh(aux->esquerda), alturaNoh(aux->direita)) + 1;

    return aux;
}

noh rotacaoEsquerda(noh raiz){
    noh aux = raiz->direita;
    noh T2 = aux->esquerda;

    aux->esquerda = raiz;
    raiz->direita = T2;

    raiz->altura = maior(alturaNoh(raiz->esquerda), alturaNoh(raiz->direita)) + 1;
    aux->altura = maior(alturaNoh(aux->esquerda), alturaNoh(aux->direita)) + 1;

    return aux;
}

noh rotacaoEsquerdaDireita(noh raiz){
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
}

noh rotacaoDireitaEsquerda(noh raiz){
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
}

noh minimo(noh raiz) {
    if (raiz != NULL) {
        noh aux = raiz;
        while (aux->esquerda != NULL) {
            aux = aux->esquerda;
        }
        return aux;
    }
    return NULL;
}

noh criar(int valor) {
    noh novo = malloc(sizeof(struct arvore));
    if (novo != NULL) {
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->valor = valor;
        novo->altura = 0;
        return novo;
    }
    printf("\nErro ao alocar item\n");
    return NULL;
}

noh inserir(noh raiz, int valor) {
    if (raiz == NULL) {
        return criar(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    } else {
        printf("\nValor Duplicado!\n");
        return raiz;
    }

    raiz->altura = 1 + maior(alturaNoh(raiz->esquerda), alturaNoh(raiz->direita));

    int balance = fatorBalanceamento(raiz);

    if (balance > 1 && valor < raiz->esquerda->valor) {
        return rotacaoDireita(raiz);
    }
    if (balance > 1 && valor > raiz->esquerda->valor) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }
    if (balance < -1 && valor > raiz->direita->valor) {
        return rotacaoEsquerda(raiz);
    }
    if (balance < -1 && valor < raiz->direita->valor) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

noh remover(noh raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            noh aux;
            if (raiz->esquerda != NULL) {
                aux = raiz->esquerda;
            }else {
                aux = raiz->direita;
            }

            if (aux == NULL) {
                aux = raiz;
                raiz = NULL;
            } else {
                *raiz = *aux;
            }
            free(aux);
            printf("\nNo removido!\n");

        } else {
            noh aux = minimo(raiz->direita);
            raiz->valor = aux->valor;
            raiz->direita = remover(raiz->direita, aux->valor);
        }
    }

    if (raiz == NULL) {
        return raiz;
    }

    raiz->altura = 1 + maior(alturaNoh(raiz->esquerda), alturaNoh(raiz->direita));

    int balance = fatorBalanceamento(raiz);

    if (balance > 1 && fatorBalanceamento(raiz->esquerda) >= 0) {
        return rotacaoDireita(raiz);
    }
    if (balance > 1 && fatorBalanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }
    if (balance < -1 && fatorBalanceamento(raiz->direita) <= 0) {
        return rotacaoEsquerda(raiz);
    }
    if (balance < -1 && fatorBalanceamento(raiz->direita) > 0) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

noh pesquisar(noh raiz, int valor) {
    if (raiz != NULL) {
        if (valor == raiz->valor) {
            return raiz;
        }
        if (valor > raiz->valor) {
            return pesquisar(raiz->direita, valor);
        }
        return pesquisar(raiz->esquerda, valor);
    }
    printf("\nA arvore esta vazia\n");
    return raiz;
}

int main() {
    int opc = 333, chave;
    noh raiz = NULL;
    do {
        printf("\n\tMenu\n\n1 - Inserir\n2 - Remover\n3 - Pesquisar\n4 - Exibir\n0 - Sair\n\nInsira sua opcao desejada: ");
        scanf("%d", &opc);
        switch (opc) {
            case 1:
                printf("\nQual o valor que deseja inserir?\n");
                scanf("%d", &chave);
                raiz = inserir(raiz, chave);
                break;
            case 2:
                printf("\nQual o valor que deseja remover?\n");
                scanf("%d", &chave);
                raiz = remover(raiz, chave);
                break;
            case 3:
                printf("\nQual o valor que deseja pesquisar?\n");
                scanf("%d", &chave);
                noh achou = pesquisar(raiz, chave);
                if (achou == NULL) {
                    printf("\nO valor %d nao existe na arvore\n", chave);
                }else{
                    printf("\nO valor %d existe na arvore\n", chave);
                }
                break;
            case 4:
                exibir(raiz, tamanhoDoEspaco);
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
                break;
        }
    }while (opc != 0);
    destruir(raiz);

    return 0;
}