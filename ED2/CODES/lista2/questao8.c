/*Crie um programa que permita realizar cadastros de alunos. Cada cadastro de alunos deve ser composto pelos seguintes dados: ano de ingresso, nome, CPF e matrícula. A matrícula deve ser gerada pelo próprio programa concatenando o sufixo do ano de ingresso com o CPF. Por exemplo, se um aluno entrou em 2019 na universidade e seu CPF for 12345678910 então o número de matrícula será 1912345678910. O seu programa deve permitir ao usuário:
a) Cadastrar novos alunos;
b) Excluir o cadastro de um aluno pelo número de matrícula;
c) Realizar a ordenação dos cadastros pelo número de matrícula;
d) Exibir uma lista com todos os cadastros;
e) Realizar a ordenação dos cadastros pelo nome. */

#include <stdio.h>
#include <string.h>
#define MAX 100
int tamanho = 0;

typedef struct {
    char cpf[12];
    int anoIngresso;
    char matricula[20];
    char nome[100];
} Aluno;

void cadastrar(Aluno aluno[], int ano, char *cpf, char *nome) {
    if (tamanho > MAX) {
        printf("\nArmazenamento lotado, não é possível cadastrar aluno\n");
    }else {
        aluno[tamanho].anoIngresso = ano;
        strcpy(aluno[tamanho].cpf, cpf);
        sprintf(aluno[tamanho].matricula, "%d%s", ano % 100, cpf);
        strcpy(aluno[tamanho].nome, nome);
        printf("\nAluno %s de matricula %s cadastrado.\n", aluno[tamanho].nome, aluno[tamanho].matricula);
        tamanho++;
    }
}

void excluirAluno(Aluno aluno[], char *matricula) {
    if (tamanho == 0) {
        printf("\nNao ha alunos cadastrados.\n");
    }else {
        int encontrado = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(aluno[i].matricula, matricula) == 0) {
                encontrado = 1;
                for (int j = i; j < tamanho - 1; j++) {
                    aluno[j] = aluno[j + 1];
                }
                tamanho--;
                printf("\nAluno excluido.\n");
                break;
            }
        }
        if (!encontrado) {
            printf("\nAluno nao registrado no armazenamento\n");
        }
    }
}

void exibirCadastros(Aluno aluno[]) {
    printf("\n\tAlunos Cadastrados\n");
    for (int i = 0; i < tamanho; i++) {
        printf("\nNome: %s, Matricula: %s, Ano de Ingresso: %d, CPF: %s", aluno[i].nome, aluno[i].matricula, aluno[i].anoIngresso, aluno[i].cpf);
    }
    printf("\n\n");
}

int particionar(Aluno aluno[], int inicio, int fim, int campo) {
    Aluno pivo = aluno[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        int condicao = 0;
        if (campo == 1) {
            condicao = strcmp(aluno[j].matricula, pivo.matricula) < 0;
        } else if (campo == 2) {
            condicao = strcmp(aluno[j].nome, pivo.nome) < 0;
        }
        if(condicao) {
            i++;
            Aluno aux = aluno[i];
            aluno[i] = aluno[j];
            aluno[j] = aux;
        }
    }
    Aluno aux = aluno[i + 1];
    aluno[i + 1] = aluno[fim];
    aluno[fim] = aux;
    return i + 1;
}

void quickSort(Aluno aluno[], int inicio, int fim, int comparador) {
    if (inicio < fim) {
        int pivo = particionar(aluno, inicio, fim, comparador);
        quickSort(aluno, inicio, pivo - 1, comparador);
        quickSort(aluno, pivo + 1, fim, comparador);
    }
}

void ordenar(Aluno aluno[], int tipo) {
    if (tipo == 1) {
        quickSort(aluno, 0, tamanho - 1, 1);
    }else if (tipo == 2) {
        quickSort(aluno, 0, tamanho - 1, 2);
    }else {
        printf("\nTipo invalido.\n");
    }
}

int main() {
    Aluno aluno[MAX];
    int opc = 333;
    do{
        printf("\n\tMenu\n0 - Sair\n1 - Cadastrar aluno\n2 - Excluir aluno\n3 - Ordenar cadastros por matricula\n4 - Exibir lista de cadastros\n5 - Ordenar cadastros por nome\n\nQual a opção desejada? ");
        scanf("%d", &opc);
        switch (opc) {
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("\nQual a quantidade de alunos que deseja cadastrar? ");
                int quantidade;
                scanf("%d", &quantidade);
                for (int i = 0; i < quantidade; i++) {
                    char nome[100], cpf[12];
                    int ano;
                    printf("\nInsira o ano de ingresso: ");
                    scanf("%d", &ano);
                    printf("\nInsira o CPF: ");
                    scanf(" %11[^\n]", cpf);
                    printf("\nInsira o nome: ");
                    scanf(" %99[^\n]", nome);
                    cadastrar(aluno, ano, cpf, nome);
                }
                break;
            case 2:
                printf("\nInsira a matricula do aluno a ser excluido: ");
                char matricula[20];
                scanf(" %19[^\n]", matricula);
                excluirAluno(aluno, matricula);
                break;
            case 3:
                ordenar(aluno, 1);
                printf("\nOrdenacao por matricula concluida.\n");
                break;
            case 4:
                exibirCadastros(aluno);
                break;
            case 5:
                ordenar(aluno, 2);
                printf("\nOrdenacao por nome concluida.\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
        }
    }while (opc != 0);
    return 0;
}