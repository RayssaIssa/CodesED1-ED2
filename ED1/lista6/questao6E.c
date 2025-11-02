/*Crie a função intercalaFila(fila f1, fila f2) que deve testar se duas filas possuem o mesmo tamanho e em caso afirmativo intercalar os elementos da fila 1 com a fila 2 e armazenar em uma fila 3. */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct FILA{
    int num[TAM], inicio, fim;
} fila;

void inicializa(fila *f){
    f->inicio = 0;
    f->fim = -1;
}

void adicionar(fila *f, int num){
    if(f->fim == TAM - 1){
        printf("\nFila cheia\n");
    }else{
        f->fim++;
        f->num[f->fim] = num;
        printf("\nNumero %d adicionado\n", num);
    }
}

int remover(fila *f){
    if(f->inicio > f->fim){
        printf("\nFila vazia\n");
        return -1;
    }else{
        int numero = f->num[f->inicio];
        f->inicio++;
        return numero;
    }
}

int testeTamanho(fila *f1, fila *f2){
    if(f1->fim == f2->fim){
        return 1;
    }else{
        return 0;
    }
}

void intercala(fila *f1, fila *f2, fila *f3){
    int i;
    for(i = 0; i < TAM; i++){
        adicionar(f3, remover(f1));
        adicionar(f3, remover(f2));
    }
}

void exibeFila(fila *f){
    int i;
    printf("\n{");
    for(i = f->inicio; i <= f->fim; i++){
        printf(" [%d]", f->num[i]);
    }
    printf(" }\n");
}

int main(){
    fila f1;
    fila f2;
    fila f3;
    inicializa(&f1);
    inicializa(&f2);
    inicializa(&f3);

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
                adicionar(&f1, valor);
                exibeFila(&f1);
                break;
            case 2:
                printf("\nDigite o valor para inserir na fila 2: ");
                scanf("%d", &valor);
                adicionar(&f2, valor);
                exibeFila(&f2);
                break;
            case 3:
                if(testeTamanho(&f1, &f2)){                    
                    intercala(&f1, &f2, &f3);
                    printf("\nElementos da fila 3: \n");
                    exibeFila(&f3);
                }else{
                    printf("\nAs filas f1 e f2 nao sao do mesmo tamanho.\n");
                }
                break;
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }while(opc != 0);
    return 0;
}