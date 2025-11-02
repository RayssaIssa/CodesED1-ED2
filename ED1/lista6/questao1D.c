/*Escreva um programa que receba do usuário o nome e a idade de uma pessoa e armazene essas informações numa estrutura de fila. Utilizando somente operações de enfileirar e desenfileirar, o seu programa deve remover um item através do nome fornecido pelo usuário. Ao final da execução da função, a fila deve ser igual à original, exceto pela ausência do item removido*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dados{    
    char nome[10];
    int idade;
};

typedef struct FILA{
    struct dados pessoa;
    struct FILA *prox;
} *Pessoa;

Pessoa criarNovo(char *nome, int idade){
    Pessoa nova = (Pessoa) malloc(sizeof(struct FILA));
    if(nova == NULL){
        printf("\nErro ao alocar memoria");
        return NULL;
    }
    strcpy(nova->pessoa.nome, nome);
    nova->pessoa.idade = idade;
    nova->prox = NULL;
    return nova;
}

Pessoa inserir(Pessoa p, char *nome, int idade){
    Pessoa nova = criarNovo(nome, idade);
    if(nova == NULL){
        return p;
    }
    if(p == NULL){
        return nova;
    }else{
        Pessoa aux = p;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = nova;
        printf("\nNome %s e idade %d inseridos\n", nova->pessoa.nome, nova->pessoa.idade);
        return p;
    }
}

int existePessoa(Pessoa p, char *nome){
    Pessoa aux = p;
    while(aux != NULL){
        if(strcmp(aux->pessoa.nome, nome) == 0){
            return 1;
        }else{
            aux = aux->prox;
        }
    }
    return 0;
}

Pessoa remover(Pessoa p, char *nome){
    if(p == NULL){
        printf("\nFila vazia");
        return NULL;
    }

    //Remove a primeira 
    if(strcmp(p->pessoa.nome, nome) == 0){
        Pessoa temporario = p->prox;
        printf("\nPessoa %s removida\n", nome);
        free(p);
        return temporario;
    }

    Pessoa aux = p;
    Pessoa aux2 = p->prox;
    while(aux2 != NULL){
        if(strcmp(aux2->pessoa.nome, nome) == 0){
            aux->prox = aux2->prox;
            free(aux2);
            aux2 = NULL;
            printf("\nPessoa %s removida\n", nome);
            return p;
        }else{
            aux = aux2;
            aux2 = aux2->prox;
        }
    }
    
    printf("\nPessoa não encontrada\n");
    return p;
}

void consultaFila(Pessoa p){
    Pessoa aux = p;
    printf("\n\tFila atual\n");
    while(aux != NULL){
        printf("\n[Pessoa %s tem %d anos]", aux->pessoa.nome, aux->pessoa.idade);
        aux = aux->prox;
    }
}

int main(){
    int idade;
    char nome[10];

    Pessoa pessoa = NULL;

    int opc = 11;
    do{
        printf("\n\tMenu\n0- Sair\n1- Inserir pessoa na fila\n2- Remover pessoa da fila\n");
        printf("Insira sua opcao: ");
        scanf("%d", &opc);

        switch (opc){
            case 0:
                printf("\nSaindo...");
                break;

            case 1:
                printf("\nInsira o nome: ");
                scanf("%s", nome);
                printf("\nInsira a idade: ");
                scanf("%d", &idade);
                pessoa = inserir(pessoa, nome, idade);
                consultaFila(pessoa);
                break;

            case 2:
                printf("\nQual o nome da pessoa a remover? ");
                scanf("%s", nome);
                if(existePessoa(pessoa, nome)){
                    pessoa = remover(pessoa, nome);
                    consultaFila(pessoa);
                }else{
                    printf("\nPessoa nao encontrada\n");
                }
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
    }while (opc != 0);  

    free(pessoa);

    return 0;
}