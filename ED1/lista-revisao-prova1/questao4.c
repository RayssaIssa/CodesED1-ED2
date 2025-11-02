#include <stdio.h>

typedef struct Pilha{
    int topo;
    int item[3];
} Pilha;

void inicializaPilha(Pilha *p){
    p->topo = -1;
}

void push(Pilha *p, int valor){
    if(p->topo == 2){
        printf("\nA pilha esta cheia!\n");
    }else{
        p->topo++;
        p->item[p->topo] = valor;
    }
}

void pop(Pilha *p){
    if(p->topo < 0){
        printf("\nPilha vazia!");
    }else{
        p->topo--;
    }
}

void exibir(Pilha *p, int n){
    int posicao = p->topo;
    printf("\n\tPilha %d\n", n);
    if(p->topo == -1){
        printf("\nPilha vazia!\n");
    }else{
        while(posicao != -1){
            printf("\t  %d\n",p->item[posicao]);
            posicao--;
        }
    }
}

void mover(Pilha *pOrigem, Pilha *pDestino){
    if(pOrigem->topo == -1){
        printf("\nA pilha origem esta vazia\n");
    }else if(pDestino->topo == 2){
        printf("\nA pilha destino esta cheia\n");
    }else{
        if(pDestino->item[pDestino->topo]){
            pDestino->topo++;
            pDestino->item[pDestino->topo] = pOrigem->item[pOrigem->topo];
            pOrigem->topo--;
        }
    }
}

int main(){
    int A, B, C;
    Pilha pilha1;
    Pilha pilha2;
    inicializaPilha(&pilha1);
    inicializaPilha(&pilha2);

    printf("\nEscreva tres valores inteiros, separados por espaco: ");
    scanf("%d %d %d", &C, &B, &A);

    push(&pilha1, C);
    push(&pilha1, B);
    push(&pilha1, A);
    exibir(&pilha1, 1);

    printf("\nFazendo primeiro movimento\n");
    mover(&pilha1, &pilha2);
    exibir(&pilha1, 1);
    exibir(&pilha2, 2);

    printf("\nFazendo segundo movimento\n");
    mover(&pilha1, &pilha2);
    exibir(&pilha1, 1);
    exibir(&pilha2, 2);

    printf("\nFazendo terceiro movimento\n");
    mover(&pilha1, &pilha2);
    exibir(&pilha1, 1);
    exibir(&pilha2, 2);
    return 0;
}