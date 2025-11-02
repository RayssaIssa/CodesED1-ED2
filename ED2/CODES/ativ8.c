#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABELA 13   
#define TAM_NOME 50
#define TAM_CURSO 30

typedef struct {
    int matricula;          
    char nome[TAM_NOME];
    char curso[TAM_CURSO];
} Aluno;

typedef struct {
    Aluno* tabela[TAM_TABELA];  
} TabelaHash;

int funcaoHash(int chave) {
    return chave % TAM_TABELA;
}

// Cria e inicializa uma tabela hash vazia
TabelaHash* criarTabelaHash() {
    TabelaHash* h = (TabelaHash*) malloc(sizeof(TabelaHash));
    if (h != NULL) {
        for (int i = 0; i < TAM_TABELA; i++)
            h->tabela[i] = NULL;
    }
    return h;
}

Aluno cadastrarAluno() {
    Aluno a;

    printf("\nDigite a matricula: ");
    scanf("%d", &a.matricula);
    getchar(); 

    printf("Digite o nome: ");
    fgets(a.nome, TAM_NOME, stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0'; // remover \n

    printf("Digite o curso: ");
    fgets(a.curso, TAM_CURSO, stdin);
    a.curso[strcspn(a.curso, "\n")] = '\0';

    return a;
}

int inserirHash(TabelaHash* h, Aluno a) {
    if (h == NULL) return 0;

    int pos = funcaoHash(a.matricula);

    if (h->tabela[pos] == NULL) {
        // Cria cópia do aluno e armazena
        Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
        *novo = a;
        h->tabela[pos] = novo;
        return 1;
    }

    printf("\nERRO: Colisao detectada para matricula %d na posicao %d.\n", a.matricula, pos);
    return 0;
}

void imprimirTabela(TabelaHash* h) {
    printf("\n--- CONTEUDO DA TABELA HASH ---\n");
    for (int i = 0; i < TAM_TABELA; i++) {
        if (h->tabela[i] != NULL) {
            printf("Posicao %d --> Matricula: %d | Nome: %s | Curso: %s\n",
                   i,
                   h->tabela[i]->matricula,
                   h->tabela[i]->nome,
                   h->tabela[i]->curso);
        } else {
            printf("Posicao %d --> [vazio]\n", i);
        }
    }
}

void pesquisar(TabelaHash* h) {
    if (h == NULL) {
        printf("\nA tabela esta vazia\n");

    }else {
        printf("\nInsira a matricula do aluno que deseja pesquisar: ");
        int matricula;
        scanf("%d", &matricula);
        getchar();

        int posicao = funcaoHash(matricula);

        if (h->tabela[posicao] != NULL && h->tabela[posicao]->matricula == matricula) {
            printf("\nO aluno de matricula %d existe na tabela\n", matricula);
            printf("\nPosicao %d --> Matricula: %d | Nome: %s | Curso: %s\n", posicao, h->tabela[posicao]->matricula, h->tabela[posicao]->nome, h->tabela[posicao]->curso);

        }else {
            printf("\nO aluno de matricula %d nao existe na tabela\n", matricula);
        }
    }
}

int main() {
    TabelaHash* tabela = criarTabelaHash();

    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir aluno\n");
        printf("2. Mostrar tabela\n");
        printf("3. Pesquisar\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1: {
                Aluno a = cadastrarAluno();
                inserirHash(tabela, a);
                break;
            }
            case 2:
                imprimirTabela(tabela);
                break;
            case 3:
                pesquisar(tabela);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while (opcao != 0);

    // Libera memória
    for (int i = 0; i < TAM_TABELA; i++)
        free(tabela->tabela[i]);
    free(tabela);

    return 0;
}