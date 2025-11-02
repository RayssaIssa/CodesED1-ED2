/*Questão 12 - Crie um programa que dado uma string, coloque as letras dela em ordem decrescente usando o algoritmo quick sort. Considere a seguinte estrutura:
struct pessoa{
    int Matricula;
    char Nome[30];
    float Nota;
};
Faça uma função que dado um vetor de tamanho N dessa estrutura, ordene o vetor pelo campo escolhido pelo usuário. */

#include <stdio.h>

typedef struct {
    int matricula;
    char nome[30];
    float nota;
}pessoa;

void inserirDados(pessoa lista[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("\nInsira a matricula: ");
        scanf("%d", &lista[i].matricula);
        printf("\nInsira o nome: ");
        scanf(" %29[^\n]", lista[i].nome);
        printf("\nInsira a nota: ");
        scanf("%f", &lista[i].nota);
    }
}

void exibir(pessoa lista[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("\nMatricula: %d\tNome: %s\tNota: %.1f\n", lista[i].matricula, lista[i].nome, lista[i].nota);
    }
}

int particionar(pessoa lista[], int inicio, int fim, int campo) {
    pessoa pivo = lista[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        int condicao = 0;
        if (campo == 1) {
            condicao = lista[j].matricula < pivo.matricula;
        } else if (campo == 2) {
            condicao = lista[j].nota < pivo.nota;
        } else if (campo == 3) {
            condicao = lista[j].nome[0] > pivo.nome[0];
        }
        if (condicao) {
            i++;
            pessoa aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
    }
    pessoa aux = lista[i + 1];
    lista[i + 1] = lista[fim];
    lista[fim] = aux;
    return i + 1;
}

void quickSort(pessoa lista[], int inicio, int fim, int comparador) {
    if (inicio < fim) {
        int pivo = particionar(lista, inicio, fim, comparador);
        quickSort(lista, inicio, pivo - 1, comparador);
        quickSort(lista, pivo + 1, fim, comparador);
    }
}

void ordenarPorCampo(pessoa lista[], int tamanho, int tipo){
    if (tipo >= 1 && tipo <= 3){
        quickSort(lista, 0, tamanho - 1, tipo);
        exibir(lista, tamanho);
    } else {
        printf("\nTipo invalido.\n");
    }
}

int main(){
    int tamanho = 2;
    pessoa lista[tamanho];
    inserirDados(lista, tamanho);
    printf("\nQual o campo desejado para ordenação?\n 1- Matricula\t2- Nome\t3- Nota");
    int tipoCampo;
    scanf("%d", &tipoCampo);
    ordenarPorCampo(lista, tamanho, tipoCampo);
    return 0;
}