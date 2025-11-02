#include <Stdio.h>
#define DISCOS 4
#define TOPO (DISCOS - 1)

typedef struct Torre{
    int topo;
    int discos[DISCOS];
} Torre;

int i;

struct Torre torre1;
struct Torre torre2;
struct Torre torre3;

void imprimir(Torre t1, Torre t2, Torre t3){
    printf("\nTorre 1\t\tTorre 2\t\tTorre 3\n");
    for(i = DISCOS - 1; i >= 0; i--){
        printf("\n");
        printf("   %d", t1.discos[i]);
        printf("\t\t   %d", t2.discos[i]);
        printf("\t\t   %d", t3.discos[i]);
    }
    printf("\n");
}

int push(Torre *t, int disco){
    if(t->topo == TOPO){
        printf("\nTorre cheia\n");
        return t->discos[t->topo];
    }else{
        t->topo++;
        t->discos[t->topo] = disco;
        return t->discos[t->topo];
    }
}

int pop(Torre *t){
    if(t->topo == -1){
        printf("\nTorre vazia");
        return -1;
    }else{
        int aux = t->discos[t->topo];
        t->discos[t->topo] = 0;
        t->topo--;
        return aux;
    }
}

void mover(int disco, Torre *antigaTorre, Torre *novaTorre){
   if(novaTorre->topo == -1 || novaTorre->discos[novaTorre->topo] > disco){
        push(novaTorre, pop(antigaTorre));
    }else{
        printf("\nNao e possivel colocar em cima de um disco maior\n\n");
    }
}

Torre* verificaTorre(int n){
    if(n == 1){
        return &torre1;
    }else if(n == 2){
        return &torre2;
    }else if(n == 3){
        return &torre3;
    }else{
        printf("Torre Invalida");
    }
}

int main(){
    printf("\nTorre de Hanoi\n\n");
    int disco, nTorre, aTorre, stop = 100, jogadas = 0;

    for(i = 0; i < DISCOS; i++){
        torre1.discos[i] = DISCOS-i;
    }
    torre1.topo = TOPO;
    torre2.topo = -1;
    torre3.topo = -1;

    imprimir(torre1, torre2, torre3);

    do{
        printf("\nDe qual torre para qual torre deseja mover? \n(Insira dois numeros separados por espaco) ");
        scanf("%d %d", &aTorre, &nTorre);

        if(aTorre == 1){
            Torre *t = verificaTorre(nTorre);
            disco = torre1.discos[torre1.topo];
            mover(disco, &torre1, t);
            jogadas++;
        }else if(aTorre == 2){
            Torre *t = verificaTorre(nTorre);
            disco = torre2.discos[torre2.topo];
            mover(disco, &torre2, t);
            jogadas++;
        }else if(aTorre == 3){
            Torre *t = verificaTorre(nTorre);
            disco = torre3.discos[torre3.topo];
            mover(disco, &torre3, t);
            jogadas++;
        }else{
            printf("\nTorre invalida\n");
        }        
        if(torre3.topo == TOPO || torre2.topo == TOPO){
            stop = 0;
        }
        imprimir(torre1, torre2, torre3);

    }while(stop != 0);

    printf("\n\t\tPARABENS!!!\n\n");
    printf("Voce conseguiu com %d jogadas!\n\n", jogadas);

    return 0;
}