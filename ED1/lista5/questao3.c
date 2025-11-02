/*Faça um programa que verifique se uma dada cadeia de caracteres é ou não palíndroma. Uma cadeia é palíndroma quando lida da esquerda para a direita e da direita para a esquerda são iguais. Por exemplo: “ARARA” é palíndroma. Para resolver o problema use uma estrutura de dados de pilha. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char item; 
    struct No *prox;
} No;
typedef struct Pilha{
    No *topo; 
} Pilha;

Pilha *criarItem(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;     
}

void empilhar(Pilha *p, char valor){
    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo == NULL){
        printf("\nNão foi possivel alocar memoria\n");
        return;
    }else{
        novoNo->item = valor;
        novoNo->prox = p->topo;
        p->topo = novoNo;
    }    
}

char desempilhar(Pilha *p){
    if(p->topo == NULL){
        printf("\nPilha Vazia\n");
        return '\0'; // Retorna um caractere nulo se a pilha estiver vazia
    }
    No *pilhaAuxiliar = p->topo;
    char valor = pilhaAuxiliar->item;
    p->topo = pilhaAuxiliar->prox;
    free(pilhaAuxiliar);
    return valor;
}

int ehPalindromo(const char *palavra){
    int i;
    int tamanho = strlen(palavra);
    Pilha *p = criarItem();

    //Empilhando
    for(i = 0; i < tamanho; i++){
        empilhar(p, palavra[i]);
    }

    //Comparando
    for(i = 0; i < tamanho; i++){
        if(palavra[i] != desempilhar(p)){
            return 0;   //Não é palindromo
        }
    }

    return 1;   //É palindromo
}

int main(){
    printf("\nQuestao 3 - Lista 5 ED1\n");
    char palavra[100]; 
    printf("\nDigite a palavra: ");
    scanf("%s", palavra);

    if(ehPalindromo(palavra)){
        printf("\nA palavra %s e palindroma\n", palavra);
    } else {
        printf("\nA palavra %s nao e palindroma\n", palavra);
    }

    return 0;
}