#include "vetor.h"

Vetor* cria(float x, float y, float z){
    Vetor* vetor = (Vetor*)malloc(sizeof(Vetor));
    if(vetor){
        vetor->x = x;
        vetor->y = y;
        vetor->z = z;
    }
    return vetor;
}

void libera(Vetor* vetor){
    free(vetor);    //Libera a memoria do vetor
}

Vetor soma(Vetor v1, Vetor v2){
    Vetor somado = {    //Soma de vetores
        v1.x + v2.x,
        v1.y + v2.y,
        v1.z + v2.z
    };
    return somado;
}

float prodInterno(Vetor v1, Vetor v2){
    float prod = (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
    return prod;
}

Vetor prodVet(Vetor v1, Vetor v2){
    Vetor vetorial = {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    };
    return vetorial;
}

void questao5(int option){
    float x1, y1, z1, x2, y2, z2;
    do{
        printf("\nDeseja fazer um novo vetor ou retornar as questoes? \n(1 - Novo vetor, 0 - Retornar as questoes/Sair): ");
        scanf("%d", &option);
        
        switch (option){
        case 1:        
            printf("\nInsira os valores do vetor 1 (x, y, z): ");
            scanf("%f %f %f", &x1, &y1, &z1);
            printf("\nInsira os valores do vetor 2 (x, y, z): ");
            scanf("%f %f %f", &x2, &y2, &z2);

            Vetor* vetorUm = cria(x1, y1, z1);
            Vetor* vetorDois = cria(x2, y2, z2);

            Vetor somas = soma(*vetorUm, *vetorDois);
            printf("\nA soma do vetor (%.1f, %.1f, %.1f) com o vetor (%.1f, %.1f, %.1f) e: (%.1f, %.1f, %.1f)\n\n", vetorUm->x, vetorUm->y, vetorUm->z, vetorDois->x, vetorDois->y, vetorDois->z, somas.x, somas.y, somas.z);

            float produtoInterno = prodInterno(*vetorUm, *vetorDois);
            printf("\nO produto interno do vetor (%.1f, %.1f, %.1f) com o vetor (%.1f, %.1f, %.1f) e: %.1f\n\n", vetorUm->x, vetorUm->y, vetorUm->z, vetorDois->x, vetorDois->y, vetorDois->z, produtoInterno);

            Vetor produtoVetorial = prodVet(*vetorUm, *vetorDois);
            printf("\nO produto vetorial do vetor (%.1f, %.1f, %.1f) com o vetor (%.1f, %.1f, %.1f) e: (%.1f, %.1f, %.1f)\n\n", vetorUm->x, vetorUm->y, vetorUm->z, vetorDois->x, vetorDois->y, vetorDois->z, produtoVetorial.x, produtoVetorial.y, produtoVetorial.z);

            libera(vetorUm);
            libera(vetorDois);

            break;
        
        case 0:
            printf("\nSaindo...\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }        

    }while(option != 0);
}