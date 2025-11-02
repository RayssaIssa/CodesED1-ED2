#include <stdio.h>
#include <stdlib.h>

#define TAM_Tabela 10
#define VAZIO -1

typedef struct Dado{
    int valor;
    int proxInt;            // encadeamento interior
    struct Dado* proxExt;   // encadeamento exterior
} Dado;

typedef struct {
    Dado* tabela[TAM_Tabela];
} Hash;

int funcaoHash(int chave) {
    return chave % TAM_Tabela;
}

Hash* criarTabela() {
    Hash* novo = (Hash*) malloc(sizeof(Hash));
    if (novo != NULL) {
        for (int i = 0; i < TAM_Tabela; i++) {
            novo->tabela[i] = NULL;
        }
    }
    return novo;
}

Dado* insereDados() {
    Dado* novo = malloc(sizeof(Dado));
    printf("\nInsira o valor: ");
    scanf("%d", &novo->valor);
    novo->proxInt = VAZIO;
    novo->proxExt = NULL;
    return novo;
}

/*       Encadeamento Exterior       */

void encadeamentoExterior(Hash* tabela, Dado* d) {
    int posicao = funcaoHash(d->valor);
    d->proxExt = tabela->tabela[posicao];     // Inserção no início
    tabela->tabela[posicao] = d;
}

/*       Encadeamento Interior       */

Dado tabelaInterna[TAM_Tabela];     // Vetor para armazenar os elementos internamente
int livre = 0;                      // controla posição livre para novos nós

void inicializarInterior() {
    for (int i = 0; i < TAM_Tabela; i++) {
        tabelaInterna[i].valor = VAZIO;
        tabelaInterna[i].proxInt = VAZIO;
    }
    livre = 0;
}

int encontrarLivre() {
    for (int i = 0; i < TAM_Tabela; i++) {
        if (tabelaInterna[i].valor == VAZIO) {
            return i;
        }
    }
    return -1;
}

void encadeamentoInterior(Dado* d) {
    int posicao = funcaoHash(d->valor);

    if (tabelaInterna[posicao].valor == VAZIO) {
        tabelaInterna[posicao].valor = d->valor;
        tabelaInterna[posicao].proxInt = VAZIO;
    } else {
        int novo = encontrarLivre();
        if (novo == -1) {
            printf("\nTabela cheia!\n");
            return;
        }

        int atual = posicao;
        while (tabelaInterna[atual].proxInt != VAZIO) {
            atual = tabelaInterna[atual].proxInt;
        }

        tabelaInterna[atual].proxInt = novo;
        tabelaInterna[novo].valor = d->valor;
        tabelaInterna[novo].proxInt = VAZIO;
    }
}

/*       Sondagem Linear       */

void sondagemLinear(Hash* tabela, Dado* d) {
    int posicao = funcaoHash(d->valor);
    int tentativas = 0;

    while (tentativas < TAM_Tabela) {
        if (tabela->tabela[posicao] == NULL) {
            tabela->tabela[posicao] = d;
            return;
        }
        posicao = (posicao + 1) % TAM_Tabela;
        tentativas++;
    }
    printf("\nTabela cheia!\n");
}


void imprimirExterior(Hash* tabela) {
    printf("\n--- ENCADEAMENTO EXTERIOR ---\n");
    for (int i = 0; i < TAM_Tabela; i++) {
        printf("[%d] -> ", i);
        Dado* atual = tabela->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proxExt;
        }
        printf("NULL\n");
    }
}

void imprimirInterior() {
    printf("\n--- ENCADEAMENTO INTERIOR ---\n");
    printf("Indice | Valor | Prox\n");
    printf("----------------------\n");
    for (int i = 0; i < TAM_Tabela; i++) {
        printf("%6d | %5d | %4d\n", i, tabelaInterna[i].valor, tabelaInterna[i].proxInt);
    }
}

void imprimirLinear(Hash* tabela) {
    printf("\n--- SONDAGEM LINEAR ---\n");
    for (int i = 0; i < TAM_Tabela; i++) {
        if (tabela->tabela[i] != NULL) {
            printf("[%d] -> %d\n", i, tabela->tabela[i]->valor);
        }else {
            printf("[%d] -> [vazio]\n", i);
        }
    }
}

int main() {
    Hash* tabela = criarTabela();
    inicializarInterior();

    int opcao, metodo;
    do {
        printf("\n--- MENU ---\n1. Inserir dado\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\nEscolha o metodo de colisao:\n0 - Sair\n1 - Encadeamento Exterior\n2 - Encadeamento Interior\n3 - Sondagem Linear\nEscolha: ");
                scanf("%d", &metodo);
                getchar();

                Dado* d = insereDados();
                if (metodo == 1) {
                    encadeamentoExterior(tabela, d);
                    imprimirExterior(tabela);

                }else if (metodo == 2) {
                    encadeamentoInterior(d);
                    imprimirInterior();

                }else if (metodo == 3) {
                    sondagemLinear(tabela, d);
                    imprimirLinear(tabela);

                }else {
                    printf("\nMetodo invalido!\n");
                }
                break;
            case 0:
                printf("\nEncerrando...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    for (int i = 0; i < TAM_Tabela; i++)
        free(tabela->tabela[i]);
    free(tabela);

    return 0;
}