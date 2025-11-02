/*Seja uma lista encadeada cujos registros possuam informação do tipo Aluno (nome e matrícula). Escreva um programa que ordena a lista em ordem crescente em relação ao nome. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char nome[10];
    int matricula;
};

typedef struct LISTA{
    struct Aluno dados;
    struct LISTA *proximo;
} *lista;

lista criarItem(char *nome, int matricula){
    lista novo = (lista) malloc(sizeof(struct LISTA));
    if(novo == NULL){
        printf("Nao foi possivel alocar memoria");
        return NULL;
    }
    strcpy(novo->dados.nome, nome);
    novo->dados.matricula = matricula;
    novo->proximo = NULL;
    return novo;
}

void exibir(lista l){
    lista aux = l;
    printf("\n\tRegistro\n");
    if(aux == NULL){
        printf("\nNao ha alunos registrados\n");
    }else{
        while(aux != NULL){
            printf("\nNome: %s - Matricula: %d", aux->dados.nome, aux->dados.matricula);
            aux = aux->proximo;
        }    
        printf("\n");
    }
}

lista ordenaCrescente(lista antigo, lista novo){
    //Admitirei que essa função foi 90% feita no chatgpt, não consegui chegar a conclusão sozinha :( 
    if(antigo == NULL || strcmp(novo->dados.nome, antigo->dados.nome) < 0){
        novo->proximo = antigo;
        return novo;
    } else {
        lista atual = antigo;
        while(atual->proximo != NULL && strcmp(novo->dados.nome, atual->proximo->dados.nome) > 0){
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
        return antigo;
    }
}

lista inserir(lista l, char *nome, int matricula){
    lista novo = criarItem(nome, matricula);
    if(novo == NULL){
        return l;
    }else if(l == NULL){
        return novo;
    }else{
        l = ordenaCrescente(l, novo);
        return l;
    }
}

int existe(lista l, int matricula){
    lista aux = l;
    while(aux != NULL){
        if(aux->dados.matricula == matricula){
            return 1;
        }else{
            aux = aux->proximo;
        }
    }
    return 0;
}

lista remover(lista l){
    if(l == NULL){
        printf("\nLista vazia\n");
        return l;
    }
    exibir(l);
    printf("\nInsira a matricula do estudante que deseja remover: ");
    int matricula;
    scanf("%d", &matricula);

    if(existe(l, matricula)){
        lista aux = l;
        // Se for o primeiro
        if(aux->dados.matricula == matricula){
            l = aux->proximo;
            free(aux);
            aux = NULL;
            return l;
        }   // Se não, procura
        while(aux->proximo->dados.matricula != matricula){
            aux = aux->proximo;
        }   //Após encontrar remove
        lista remove = aux->proximo;
        aux->proximo = remove->proximo;
        printf("\nAluno %s removido com sucesso!\n", remove->dados.nome);
        free(remove);
        remove = NULL;
        return l;
    }else{
        printf("\nMatricula invalida\n");
        return l;
    }
}

int main(){
    lista registro = NULL;
    int opc = 333, matricula;
    char nome[10];
    do{
        printf("\n\tMenu\n0 - Sair\n1 - Exibir registro\n2 - Inserir novo aluno\n3 - Remover aluno\n");
        printf("\nInsira a opcao desejada: ");
        scanf("%d", &opc);
        switch (opc){
        case 0:
            printf("\nSaindo...");
            break;

        case 1:
            exibir(registro);
            break;

        case 2:
            printf("\nInsira o nome do aluno: ");
            scanf("%s", nome);
            printf("\nInsira a matricula: ");
            scanf("%d", &matricula);
            registro = inserir(registro, nome, matricula);
            break;

        case 3:
            registro = remover(registro);
            break;

        default:
            printf("\nOpcao invalida");
            break;
        }
    }while(opc != 0);
    free(registro);
    return 0;
}