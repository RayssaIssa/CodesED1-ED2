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
#define TAM 5

struct Paciente{
    char nome[10];
    int idade;
};

typedef struct FILA{
    struct Paciente paciente[TAM];
    int inicio, fim;
} Registro;

int pacientes = 0;

void inicializa(Registro *r){
    r->inicio = 0;
    r->fim = -1;
}

void inserir(Registro *r, char *nome, int idade){
    int i;
    if(r->fim == TAM - 1){
        printf("\nFila cheia\n");
        return;
    }
    pacientes++;
    r->fim++;
    if(idade >= 60){
        for(i = r->fim; i > r->inicio; i--){
            r->paciente[i] = r->paciente[i - 1];
        }
        strcpy(r->paciente[r->inicio].nome, nome);
        r->paciente[r->inicio].idade = idade;
        printf("\nPaciente Prioritario %s registrado\n", nome);
    }else {
        strcpy(r->paciente[r->fim].nome, nome);
        r->paciente[r->fim].idade = idade;
        printf("\nPaciente %s registrado\n", nome);
    }
}

void remover(Registro *r){
    if(r->inicio > r->fim){
        printf("\nFila vazia\n");
    }else{
        printf("\nPaciente %s foi para atendimento\n", r->paciente[r->inicio].nome);
        r->inicio++;
        pacientes--;
    }
}

void exibir(Registro *r){
    int i;
    for(i = r->inicio; i <= r->fim; i++){
        printf("\n[Paciente: %s | Idade: %d]", r->paciente[i].nome, r->paciente[i].idade);
    }
}

int main(){
    int opc = 111;
    Registro registro;
    inicializa(&registro);
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
                inserir(&registro, nome, idade);
                exibir(&registro);
                break;

            case 2:
                remover(&registro);
                break;

            case 3:
                if(registro.inicio > registro.fim){
                    printf("\nNao ha pacientes na fila\n");
                }else{
                    printf("\nExistem pacientes na fila!\n");
                }
                break;
                
            case 4:
                if(pacientes <= 0){
                    printf("\nNao ha pacientes na fila\n");
                }else{
                    printf("\nProximo paciente a ser atendido:\tNome: %s, Idade: %d\n", registro.paciente[registro.inicio].nome, registro.paciente[registro.inicio].idade);
                }
                break;
            
            case 5:
                printf("\nExistem %d pacientes na fila de espera\n", pacientes);
                break;

            default:
                printf("\nOpcao invalida");
                break;
        }
    }while(opc != 0);
    return 0;
}