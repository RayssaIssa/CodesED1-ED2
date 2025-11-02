#include<stdio.h>
#include <stdlib.h>

// particionar e retorna o índice do pivô
int particionar(int *vetor, int inicio, int fim)
{
    int pivo = vetor[fim];
    int i = inicio - 1;

    for(int j = inicio; j <= fim-1; j++)
    {
        if(vetor[j] <= pivo)
        {
            i++;
            int aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }

    //coloca o pivô no lugar correto
    int aux = vetor[i+1];
    vetor[i+1] = vetor[fim];
    vetor[fim] = aux;
    return i+1;
}

void quickSort(int *vetor, int inicio, int fim)
{
    if(inicio < fim)
    {
        int pivoIndice = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, pivoIndice - 1);
        quickSort(vetor, pivoIndice + 1, fim);
    }
}


int main ()
{

 int vetor[10]={7,3,1,2,8,10,6,5,9,4};
 

printf("\nVETOR INICIAL\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }

quickSort(vetor, 0, 9);

printf("\n\nVETOR ORDENADO\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }
getchar();
 return 0;

}