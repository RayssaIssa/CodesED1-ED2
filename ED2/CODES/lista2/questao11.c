/* Faça um programa em linguagem de programação C que seja capaz de ordenar um baralho de cartas usando o método de ordenação por distribuição. Você pode considerar que o baralho possuirá apenas as seguintes cartas:

As < 2 < 3 < J < Q < K com os naipes paus < ouro < copas < espada

O seu algoritmo deve ser capaz de gerar o baralho, embaralhar as cartas e em seguida ordená-las. Todas as operações realizadas pelo seu programa devem ser exibidas na tela para o usuário.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int const tamanho = 6*4;
int geradas = 0;

typedef struct {
    char naipe[10];
    char carta[6];
} Baralho;

void exibir(Baralho cartas[], int limite){
    printf("\n\tBaralho Atual\n");
    for(int i = 0; i < limite; i++){
        printf("[%s de %s] ", cartas[i].carta, cartas[i].naipe);
        if (i == 5 || i == 11 || i == 17 || i == 23) {
            printf("\n");
        }
    }
    printf("\n");
}

void geraBaralho(Baralho cartas[]) {
    char *nuns[6] = {"AS", "2", "3", "J", "Q", "K"};
    char *naipe[10] = {"Paus", "Ouro", "Copas", "Espada"};
    printf("\n\n\t\tGERACAO DAS CARTAS DO BARALHO\n");

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < tamanho/4; i++) {
            strcpy(cartas[geradas].carta, nuns[i]);
            strcpy(cartas[geradas].naipe, naipe[k]);
            geradas++;
            exibir(cartas, geradas);
        }
    }
}

void embaralha(Baralho cartas[]) {
    printf("\n\n\t\tEMBARALHANDO AS CARTAS DO BARALHO\n");
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Baralho aux = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = aux;
        exibir(cartas, tamanho);
    }
}

int main() {
    srand(time(NULL));
    Baralho cartas[tamanho];
    geraBaralho(cartas);
    embaralha(cartas);
    return 0;
}