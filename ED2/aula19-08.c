#include <stdio.h>

void exibir(int vetor[], int tamanho){
    //printf("\n");
    int i = 0;
    while(i < tamanho){
        printf("[%d] ", vetor[i]);
        i++;
    }
    printf("\n\n");
}

void juntar(int a[], int b[], int c[], int d[], int e[], int aux[], int tamanho){
    int entrou = 0;
        int  n = 0;
        while(n < tamanho){
            if(a[n] != 0){
                aux[entrou] = a[n];
                entrou++;
            }
            n++;
        }
        n = 0;
        while(n < tamanho){
            if(b[n] != 0){
                aux[entrou] = b[n];
                entrou++;
            }
            n++;
        }
        n = 0;
        while(n < tamanho){
            if(c[n] != 0){
                aux[entrou] = c[n];
                entrou++;
            }
            n++;
        }
        n = 0;
        while(n < tamanho){
            if(d[n] != 0){
                aux[entrou] = d[n];
                entrou++;
            }
            n++;
        }
        n = 0;
        while(n < tamanho){
            if(e[n] != 0){
                aux[entrou] = e[n];
                entrou++;
            }
            n++;
        }
}

void inicializaVetor(int vetor[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        vetor[i] = 0;
    }
}

void bucketSort(int vetor[], int tamanho){
    int i, A[tamanho], B[tamanho], C[tamanho], D[tamanho], E[tamanho], final[tamanho];
    inicializaVetor(A, 9);
    inicializaVetor(B, 9);
    inicializaVetor(C, 9);
    inicializaVetor(D, 9);
    inicializaVetor(E, 9);
    int at = 0;
    int bt = 0;
    int ct = 0;
    int dt = 0;
    int et = 0;

    for(i = 0; i < tamanho; i++){
        if(vetor[i] >= 0 && vetor[i] <= 20){
            A[at] = vetor[i];
            at++;
            insertionSort(A, tamanho);

        }else if(vetor[i] >= 21 && vetor[i] <= 40){
            B[bt] = vetor[i];
            bt++;
            insertionSort(B, tamanho);

        }else if(vetor[i] >= 41 && vetor[i] <= 60){
            C[ct] = vetor[i];
            ct++;
            insertionSort(C, tamanho);

        }else if(vetor[i] >= 61 && vetor[i] <= 80){
            D[dt] = vetor[i];
            dt++;
            insertionSort(D, tamanho);

        }else if(vetor[i] >= 81 && vetor[i] <= 100){
            E[et] = vetor[i];
            et++;
            insertionSort(E, tamanho);
        }
    }

    printf("Original ");
    exibir(vetor, tamanho);

    printf("A ");
    exibir(A, tamanho);

    printf("B ");
    exibir(B, tamanho);

    printf("C ");
    exibir(C, tamanho);

    printf("D ");
    exibir(D, tamanho);

    printf("E ");
    exibir(E, tamanho);

    juntar(A, B, C, D, E, final, 9);

    printf("Final Ordenado ");
    exibir(final, tamanho);
}

void insertionSort(int vetor[], int tamanho){
    int i, j, chave;
    for(i = 1; i < tamanho; i++){
        chave = vetor[i];
        j = i - 1;
        while(j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
        exibir(vetor, tamanho);
    }
}

int main(){
    int vetor[9] = {3, 100, 78, 61, 11, 23, 97, 33, 40};
    bucketSort(vetor, 9);
    return 0;
}