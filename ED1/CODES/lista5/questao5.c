/*Crie a função intercalaPilha(pilha p1, pilha p2) que deve testar se duas pilhas estáticas possuem o mesmo tamanho e em caso afirmativo intercalar os elementos da pilha 1 com a pilha 2 e armazenar em uma pilha 3 (também estática). */

#include <stdio.h>

typedef struct{
    int item[5];
    int topo;
} pilha;

void inicializaPilha(pilha *p){
    p->topo = -1;
}

int pilhaCheia(pilha *p, int tamanho){
    if(p->topo == tamanho){
        printf("\nPilha cheia\n");
        return 1;
    }else{
        return 0;
    }
}

int pilhaVazia(pilha *p){
    if(p->topo == -1){
        printf("\nPilha vazia\n");
        return 1;
    }else{
        return 0;
    }
}

void push(pilha *p, int tamanho, int valor){
    if(pilhaCheia(p, tamanho)){
        return;
    }else{
        p->topo++;
        p->item[p->topo] = valor;
        printf("\nItem insirido\n");
    }
}

int pop(pilha *p, int *valor){
    if(pilhaVazia(p)){
        return 0;
    }else{
        *valor = p->item[p->topo];
        p->topo--;
        printf("\nItem removido\n");
        return 1;
    }
}

int tamanhoPilha(pilha *p) {
    return p->topo + 1;
}

void exibe(pilha *p, int n){
    int i;
    printf("\n\nPilha %d\n", n);
    for(i = 0; i <= p->topo; i++){
        printf("%d", p->item[i]);
    }
}

int intercalaPilha(pilha *p1, pilha *p2, pilha *p3){
    int v;
    if (tamanhoPilha(p1) != tamanhoPilha(p2)) {
        return 0; 
    }
    pilha aux1, aux2;
    inicializaPilha(&aux1);
    inicializaPilha(&aux2);
    while (!pilhaVazia(p1)) {
        pop(p1, &v);
        push(&aux1, 5, v);
    }
    while (!pilhaVazia(p2)) {
        pop(p2, &v);
        push(&aux2, 5, v);
    }

    // Intercala os elementos das duas pilhas
    while (!pilhaVazia(&aux1) && !pilhaVazia(&aux2)) {
        pop(&aux1, &v);
        push(p1, 5, v);  
        push(p3, 5, v);  

        pop(&aux2, &v);
        push(p2, 5, v);  
        push(p3, 5, v);  
    }

    return 1;
}

int main(){
    printf("\n\tQuestao 5 - Lista 5 ED1 - Rayssa\n");
    pilha p1, p2, p3;
    inicializaPilha(&p1);
    inicializaPilha(&p2);
    inicializaPilha(&p3);

    push(&p1, 5, 2);
    push(&p1, 5, 4);
    push(&p2, 5, 8);
    push(&p2, 5, 6);

    if(intercalaPilha(&p1, &p2, &p3)){
        exibe(&p1, 1);
        exibe(&p2, 2);
        exibe(&p3, 3);
    }else{
        printf("\nAs pilhas possuem tamanhos diferentes\n");
    }
    return 0;
}