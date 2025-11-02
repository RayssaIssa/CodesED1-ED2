/*Seja S uma sequência formada por 20 números inteiros. Codifique um programa que empilhe na pilha A os números pares e na pilha B os números ímpares. */
#include <stdio.h>
#include <stdlib.h>
typedef struct ITEM{
    int numero;
    struct ITEM *proximo;
} *pilha;

pilha criarItem(int valor){
	pilha novoItem = (pilha) malloc(sizeof(struct ITEM));
	if(novoItem == NULL){
        printf("\nErro ao criar item!\n");
        return NULL;
	}else{
        novoItem->numero = valor;
        novoItem->proximo = NULL;
        return novoItem;
	}
}

void push(pilha *p, int valor){
    pilha novoItem = criarItem(valor);
    if (novoItem == NULL) return;
    novoItem->proximo = *p;
    *p = novoItem;
}

void exibe(pilha p){
    while(p != NULL){
		printf("%d ", p->numero);
		p = p->proximo;
	}
}

void verificaNum(int num[], pilha *pA, pilha *pB){
    int i;
    for(i = 0; i < 20; i++){
        if(num[i] % 2 == 0){
            push(pA, num[i]);
        }else{
            push(pB, num[i]);
        }
    }
}

int main(){
    pilha pilhaA = NULL; 
    pilha pilhaB = NULL;

    int S[20], i;
    printf("\nInsira separado por enter os 20 valores de S: ");
    for(i = 0; i < 20; i++){
        scanf("%d", &S[i]);
        //S[i] = i+1;
    }

    verificaNum(S, &pilhaA, &pilhaB);

    printf("\nSequencia S\n");
    for(i = 0; i < 20; i++){
        printf("%d ", S[i]);
    }

    printf("\nPilha A dos numeros pares: ");
    exibe(pilhaA);
    printf("\nPilha B dos numeros impares: ");
    exibe(pilhaB);

    return 0;
}