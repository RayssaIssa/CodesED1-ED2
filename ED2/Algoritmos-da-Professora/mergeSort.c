#include<stdio.h>
#include <stdlib.h>


void intercalar(int *vetor, int tamanho) 
{
    //trata o vetor como duas metades. i percorrerá a primeira metade e j a segunda
    int meio = tamanho / 2;
    int i = 0, j = meio, k = 0;
    int auxiliar[tamanho]; //é preciso um vetor auxiliar para armazenar os valores ordenados
    
    //enquanto houver elementos no vetor
    while( i < meio && j < tamanho )
    {
        // pega o menor deles e coloca no aux
         if( vetor[i] <= vetor[j] )
            auxiliar[k] = vetor[i++];
         else
            auxiliar[k] = vetor[j++];
        k++;
      
    }
    //se a primeira metade acabou, então copia o resto da segunda metade. E vice-versa
    if( i == meio )
        while( j < tamanho )
            auxiliar[k++] = vetor[j++];
     else
         while( i < meio )
         auxiliar[k++] = vetor[i++];
    
    //depois de tudo, copia o vetor auxiliar para o vetor original
    for( i = 0; i < tamanho; i++ )
        vetor[i] = auxiliar[i];
}

void mergeSort(int *vetor, int tamanho){

    int meio = tamanho / 2;
    if( tamanho > 1 ){
        mergeSort(vetor, meio);
        mergeSort(vetor + meio, tamanho - meio);
        intercalar(vetor, tamanho);
    }
}

int main ()
{

 int vetor[10]={7,3,1,2,8,10,6,5,9,4};
 
 int i=0;

printf("\nvetor antes da ordenacao\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }

mergeSort(vetor, 10);

printf("\n\nvetor ordenado\n");
 for (int i = 0; i < 10; i++)
 {
   printf("[%d] ",vetor[i]);
 }
getchar();
 return 0;

}