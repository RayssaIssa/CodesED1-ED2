/*Crie um programa para gerenciar o atendimento em um consultório médico. Os pacientes são registrados no sistema assim que chegam no consultório. Após o registro eles ficam aguardando o chamado do médico, que obedece a ordem de chegada. Cada paciente deve ter no mínimo o nome e a idade.  O programa deve ser capaz de: 
a) Inserir um paciente na fila de espera;  
b) Chamar o paciente para ser atendido;  
c) Verificar se a fila está cheia ou vazia;  
d) Verificar o próximo paciente a ser atendido;  
e) Informar quantos pacientes existem na fila de espera; 
f) Permitir atendimento prioritário, onde os pacientes mais velhos são 
atendimentos primeiro.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paciente{
    char nome[10];
    int idade;
};

typedef struct FILA{
    struct Paciente paciente;
    struct FILA *prox;
} *Registro;

int pacientes = 0;

Registro criarRegistro(char *nome, int idade){
    Registro novo = (Registro) malloc(sizeof(struct FILA));
    if(novo == NULL){
        printf("\nNao foi possivel alocar memoria");
        return NULL;
    }
    strcpy(novo->paciente.nome, nome);
    novo->paciente.idade = idade;
    novo->prox = NULL;
    return novo;
}

Registro inserir(Registro r, char *nome, int idade){
    Registro novo = criarRegistro(nome, idade);
    if(novo == NULL){
        return r;
    }
    if(r == NULL){
        pacientes++;
        return novo;
    }else{
        if(idade >= 60){
            printf("\nPaciente prioritario!\n");
            novo->prox = r;
            pacientes++;
            printf("\nPaciente %s inserido\n", nome);
            return novo;
        }else{
            Registro aux = r;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
            pacientes++;
            printf("\nPaciente %s inserido\n", nome);
            return r;
        }
    }
}

Registro remover(Registro r){
    if(r == NULL){
        printf("\nNao ha pacientes na fila\n");
        return NULL;
    }    
    printf("\nPaciente %s prossiga para ser atendido!\n", r->paciente.nome);
    Registro aux = r;
    r = r->prox;
    pacientes--;
    free(aux);
    aux = NULL;
    return r;
}

void exibir(Registro r){
    Registro aux = r;
    printf("\n\tFila de espera atual\n");
    while(aux != NULL){
        printf(" [Paciente %s de idade %d] ", aux->paciente.nome, aux->paciente.idade);
        aux = aux->prox;
    }
}

int main(){
    int opc = 111;
    Registro registro = NULL;
    do{
        printf("\n\tMenu\n\n0 - Sair\n1 - Inserir um paciente na fila de espera (Permitir atendimento prioritario, onde os pacientes mais velhos sao atendimentos primeiro)\n2 - Chamar o paciente para ser atendido\n3 - Verificar se a fila esta cheia ou vazia\n4 - Verificar o proximo paciente a ser atendido\n5 - Informar quantos pacientes existem na fila de espera\n");

        printf("Digite a opcao escolhida: ");
        scanf("%d", &opc);
        switch(opc){
            case 0:
                printf("\nSaindo...\n");
                break;

            case 1:
                printf("\nInsira o nome do paciente: ");
                char nome[10];
                scanf("%s", nome);
                printf("\nInsira a idade do paciente: ");
                int idade;
                scanf("%d", &idade);
                registro = inserir(registro, nome, idade);
                exibir(registro);
                break;

            case 2:
                registro = remover(registro);
                break;

            case 3:
                if(registro == NULL){
                    printf("\nNao ha pacientes na fila\n");
                }else{
                    printf("\nExistem pacientes na fila!\n");
                }
                break;
                
            case 4:
                printf("\nProximo paciente a ser atendido:\tNome: %s, Idade: %d\n", registro->paciente.nome, registro->paciente.idade);
                break;
            
            case 5:
                printf("\nExistem %d pacientes na fila de espera\n", pacientes);
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(opc != 0);
    free(registro);
    return 0;
}