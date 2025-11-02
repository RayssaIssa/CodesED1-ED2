#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "questao1.h"
#include "questao2.h"
#include "questao3.h"
#include "questao4.h"

int main(){ 
    int option;
    printf("\n\tLista 3 - ED 1 - by Rayssa\n");
    do{
        printf("\n\tMenu\n");
        printf("\n0 - Sair\n1 - Questao 1\n2 - Questao 2\n3 - Questao 3\n4 - Questao 4\nEscolha a opcao desejada: ");
        scanf("%d", &option);

        switch (option){
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("\n\t--- Questao 1 ---\n");
            questao1(option);
            break;

        case 2:
            printf("\n\t--- Questao 2 ---\n");
            questao2(option);
            break;

        case 3:
            printf("\n\t--- Questao 3 ---\n");
            questao3(option);
            break;

        case 4:
            printf("\n\t--- Questao 4 ---\n");
            questao4(option);
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }

    }while(option != 0);
    return 0;
}