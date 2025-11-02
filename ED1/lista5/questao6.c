/*A Torre de Hanói é um famoso quebra-cabeça matemático que consiste em três hastes e um número de discos de tamanhos diferentes que podem ser encaixados uma vez em cada haste. O objetivo é mover a pilha inteira de discos de uma haste para outra, respeitando as seguintes regras: 
● Só é permitido mover um disco de cada vez. 
● Um disco maior nunca pode ser colocado sobre um disco menor. 
Escreva um programa em C que resolva o problema da Torre de Hanói usando pilhas. 
Seu programa deve incluir as seguintes funcionalidades: 
● Definição de uma estrutura de dados do tipo pilha. 
● Implementação das operações de empilhar (push) e desempilhar (pop) para a pilha. 
● Função para resolver a Torre de Hanói para um número específico de discos (no mínimo 3 discos).. 
● O programa deve imprimir cada movimento realizado, indicando a origem e o destino do disco movido. 
Observação:  
● As hastes são geralmente representadas pelas letras A, B e C.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *discos;
    char nome;
    int topo;
} Pilha;
int i;
void inicializa(Pilha *p, char nome, int quantDiscos){
    p->nome = nome;
    p->topo = -1;
    p->discos = (int*) malloc(quantDiscos * sizeof(int));
    if (p->discos == NULL) {
        printf("\nErro ao alocar memoria\n");
        exit(1);
    }
    for(i = quantDiscos; i >= 0; i--){
        p->discos[i] = 0;
    }
}

Pilha* verificaTorre(char a, Pilha *A, Pilha *B, Pilha *C){
    if(a == 'A'){
        return A;
    }else if(a == 'B'){
        return B;
    }else if(a == 'C'){
        return C;
    }else{
        printf("Torre Invalida");
        return NULL;
    }
}

void imprimir(Pilha t1, Pilha t2, Pilha t3, int quantDiscos){
    printf("\nTorre A\t\tTorre B\t\tTorre C\n");
    for(i = quantDiscos - 1; i >= 0; i--){
        printf("\n");
        printf("   %d", t1.discos[i]);
        printf("\t\t   %d", t2.discos[i]);
        printf("\t\t   %d", t3.discos[i]);
    }
    printf("\n");
}

int pop(Pilha *p){
    if(p->topo == -1){
        printf("\nTorre vazia\n");
        return 0;
    }
    int aux = p->discos[p->topo];
    p->discos[p->topo] = 0;
    p->topo--;
    return aux;
}

void push(Pilha *p, int valor, int quantDiscos){
    if(p->topo == quantDiscos){
        printf("\nTorre cheia\n");
        return;
    }
    p->topo++;
    p->discos[p->topo] = valor;
}

void movimento(Pilha *pO, Pilha *pD, int disco, int *mov, int quantDisco){
    if(pD->topo == -1 || pD->discos[pD->topo] > disco){
        push(pD, pop(pO), quantDisco);
        (*mov)++;
        printf("\nMovimeto %d: Mover disco %d da haste %c para a haste %c", *mov, disco, pO->nome, pD->nome);
    }else{
        printf("\nNao e possivel colocar em cima de um disco maior\n\n");
    }
}

int main(){
    int quantDiscos;
    printf("\nQuestao 6 - Lista 5 ED1 - Rayssa\n");
    printf("\nInsira a quantidade de discos (minimo 3): ");
    scanf("%d", &quantDiscos);
    if(quantDiscos < 3){
        printf("\nQuantidade invalida. Saindo...");
        return 0;
    }

    Pilha A, B, C;
    inicializa(&A, 'A', quantDiscos);
    for(i = quantDiscos; i > 0; i--){
        A.discos[++A.topo] = i;
    }
    inicializa(&B, 'B', quantDiscos);
    inicializa(&C, 'C', quantDiscos);

    printf("\nNumero de discos: %d\n", quantDiscos);

    int jogadas = 0, stop = 100;
    char aTorre, nTorre;
    do{
        printf("\nDe qual torre para qual torre deseja mover? \n(Insira as letras separadas por espaco) ");
        scanf(" %c %c", &aTorre, &nTorre);
        
        if(aTorre == 'A'){
            Pilha *t = verificaTorre(nTorre, &A, &B, &C);
            if (t != NULL)
                movimento(&A, t, A.discos[A.topo], &jogadas, quantDiscos);
        }else if(aTorre == 'B'){
            Pilha *t = verificaTorre(nTorre, &A, &B, &C);
            if (t != NULL)
                movimento(&B, t, B.discos[B.topo], &jogadas, quantDiscos);            
        }else if(aTorre == 'C'){
            Pilha *t = verificaTorre(nTorre, &A, &B, &C);
            if (t != NULL)
                movimento(&C, t, C.discos[C.topo], &jogadas, quantDiscos);            
        }else{
            printf("\nTorre invalida\n");
        }        
        if(B.topo == quantDiscos - 1 || C.topo == quantDiscos - 1){
            stop = 0;
        }
        imprimir(A, B, C, quantDiscos);

    }while(stop != 0);

    printf("\n\t\tPARABENS!!!\n\n");
    printf("Voce conseguiu com %d jogadas!\n\n", jogadas);

    free(A.discos);
    free(B.discos);
    free(C.discos);
    return 0;
}