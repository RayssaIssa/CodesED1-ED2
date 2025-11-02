/*Escreva um programa que receba do usuário o nome e a idade de uma pessoa e armazene essas informações numa estrutura de pilha (estática ou dinâmica). Utilizando somente operações de empilhar e desempilhar, o seu programa deve remover um item por meio do nome fornecido pelo usuário. Ao final da execução da função, a pilha deve ser igual a original, exceto pela ausência do item removido. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
} Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No *prox;
} No;
int i;

void push(No **topo, Pessoa p){
    No *novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro de alocação!\n");
        return;
    }
    novoNo->pessoa = p;
    novoNo->prox = *topo;
    *topo = novoNo;
}

Pessoa pop(No **topo){
    Pessoa p;
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        p.nome[0] = '\0';
        p.idade = -1;
        return p;
    }
    No *auxiliar = *topo;
    p = auxiliar->pessoa;
    *topo = auxiliar->prox;
    free(auxiliar);
    return p;
}

void remover(No **topo, char nome[]) {
    No *aux = NULL; 
    int encontrado = 0;

    while (*topo != NULL) {
        Pessoa p = pop(topo);
        if (strcmp(p.nome, nome) == 0) {
            encontrado = 1;
            printf("\nRemovendo: %s\n", p.nome);
            break;
        }
        push(&aux, p);
    }
    while (aux != NULL) {
        push(topo, pop(&aux));
    }
    if (!encontrado) {
        printf("\nPessoa com nome '%s' nao encontrada\n", nome);
    }
}

void imprimir(No *topo) {
    No *aux = topo;
    printf("\nPilha:\n");
    while (aux != NULL) {
        printf("Nome: %s, Idade: %d\n", aux->pessoa.nome, aux->pessoa.idade);
        aux = aux->prox;
    }
}

int main(){
    No *pilha = NULL;
    int n;

    printf("\nQuantas pessoas deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); 

    for (i = 0; i < n; i++) {
        Pessoa p;
        printf("\nDigite o nome da pessoa %d: ", i + 1);
        fgets(p.nome, sizeof(p.nome), stdin);
        p.nome[strcspn(p.nome, "\n")] = '\0';
        printf("Digite a idade: ");
        scanf("%d", &p.idade);
        getchar(); 
        push(&pilha, p);
    }
    imprimir(pilha);

    char pessoaRemover[50];
    printf("\nDigite o nome da pessoa a ser removida: ");
    fgets(pessoaRemover, sizeof(pessoaRemover), stdin);
    pessoaRemover[strcspn(pessoaRemover, "\n")] = '\0';

    remover(&pilha, pessoaRemover);
    imprimir(pilha);
    return 0;
}