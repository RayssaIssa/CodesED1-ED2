/*Crie a função intercalaFila(fila f1, fila f2) que deve testar se duas filas possuem o mesmo tamanho e em caso afirmativo intercalar os elementos da fila 1 com a fila 2 e armazenar em uma fila 3. */

#include <stdio.h>
#include <stdlib.h>

typedef struct FILA{
    int num;
    struct FILA *prox;
} *fila;
int tam = 0;

fila criarItem(int num){
    fila novo = (fila) malloc(sizeof(struct FILA));
    if(novo == NULL){
        printf("\nFalha ao alocar memoria");
        return NULL;
    }
    novo->num = num;
    novo->prox = NULL;
    return novo;
}

fila adicionar(fila f, int num){
    fila novo = criarItem(num);
    if(novo == NULL){
        return NULL;
    }else if(f == NULL){
        printf("\nItem %d adicionado", num);
        return novo;
    }else{
        fila aux = f;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        printf("\nItem %d adicionado", num);
        return f;
    }
}

int remover(fila *f){
    if(*f == NULL){
        printf("\nFila vazia\n");
        return -1;
    }
    fila aux = *f;
    int numero = aux->num;
    *f = aux->prox;
    free(aux);
    aux = NULL;
    return numero;
}

int testeTamanho(fila f1, fila f2){
    int tam1 = 0, tam2 = 0;
    fila aux1 = f1;
    fila aux2 = f2;
    while(aux1 != NULL){
        tam1++;
        aux1 = aux1->prox;
    }    
    while(aux2 != NULL){
        tam2++;
        aux2 = aux2->prox;
    }
    if(tam1 == tam2){
        tam = tam1;
        return 1;
    }else{
        return 0;
    }
}

fila intercala(fila *f1, fila *f2){
    fila f3 = NULL;
    int n = 0;

    while(n < tam){
        f3 = adicionar(f3, remover(f1));
        f3 = adicionar(f3, remover(f2));
        n++;
    }
    return f3;
}

void exibeFila(fila f){
    fila aux = f;
    printf("\n[");
    while(aux != NULL){
        printf(" %d", aux->num);
        aux = aux->prox;
    }
    printf(" ]\n");
}

int main(){
    fila f1 = NULL;
    fila f2 = NULL;
    fila f3 = NULL;

    int opc = 111, valor;
    do{
        printf("\nMenu\n0 - Sair\n1 - Inserir valores na fila 1\n2 - Inserir valores na fila 2\n3 - Intercalar elementos na fila 3\n");
        scanf("%d", &opc);
        switch(opc){
            case 0:
            printf("\nSaindo...");
            break;
            case 1:
                printf("\nDigite o valor para inserir na fila 1: ");
                scanf("%d", &valor);
                f1 = adicionar(f1, valor);
                exibeFila(f1);
                break;
            case 2:
                printf("\nDigite o valor para inserir na fila 2: ");
                scanf("%d", &valor);
                f2 = adicionar(f2, valor);
                exibeFila(f2);
                break;
            case 3:
                if(testeTamanho(f1, f2)){                    
                    f3 = intercala(&f1, &f2);
                    printf("\nElementos da fila 3: \n");
                    exibeFila(f3);
                }else{
                    printf("\nAs filas f1 e f2 nao sao do mesmo tamanho.\n");
                }
                break;
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }while(opc != 0);

    free(f1);
    free(f2);
    free(f3);
    return 0;
}