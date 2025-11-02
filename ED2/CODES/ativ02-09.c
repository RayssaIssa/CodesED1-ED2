#include <stdio.h>
#include <windows.h>

typedef struct {
    int codigo;
    char nome[50];
    double preco;
} Produto;

char *name[10] = {"Maca", "Banana", "Uva", "Laranja", "Limao", "Pera", "Tangerina", "Amora", "Maracuja", "Caju"};
double valor = 5;

void inserirDados(Produto lista[], int quantidade) {
    int codigo = 1;
    for (int i = 0; i < quantidade; i++) {
        lista[i].codigo = codigo;
        strcpy(lista[i].nome, name[i]);
        lista[i].preco = valor;
        codigo++;
        valor++;
    }
}

int buscaSequencial(Produto lista[], int quantidade, char *chave) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(lista[i].nome, chave) == 0) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(Produto lista[], int quantidade, int code) {
    int esq = 0, dir = quantidade - 1;
    do {
        if (esq > dir) {
            return -1;
        }
        int i = (esq + dir)/2;
        if (i == code) {
            return i;
        }else if (code < i) {
            dir-=1;
        }else {
            esq+=1;
        }

    }while (1);
}

int main() {
    int quantidade = 10;

    Produto lista[quantidade];
    inserirDados(lista, quantidade);

    /*printf("\nQual o produto que deseja buscar? ");
    char chave[50];
    fgets(chave, sizeof(chave), stdin);
    chave[strcspn(chave, "\n")] = '\0';

    int code = buscaSequencial(lista, quantidade, chave);*/

    printf("\nQual o codigo do produto: ");
    int id;
    scanf("%d", &id);
    int code = buscaBinaria(lista, quantidade, id-1);

    if (code != -1) {
        printf("\nO produto foi encontrado.\nCodigo: %d, Nome: %s, Preco (Kg): R$%2.f\n", lista[code].codigo, lista[code].nome, lista[code].preco);
    }else {
        printf("\nProduto nao encontrado.\n");
    }

    return 0;
}