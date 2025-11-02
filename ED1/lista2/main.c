#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "questao1.h"
#include "questao2.h"
#include "questao3.h"
#include "questao4.h"
#include "questao5.h"
#include "questao6.h"

int main(){
    int option;

    do{
        printf("\n\tMenu\n");
        printf("\n0 - Sair\n1 - Questao 1\n2 - Questao 2\n3 - Questao 3\n4 - Questao 4\n5 - Questao 5\n6 - Questao 6\n\nDigite a opcao desejada: ");
        scanf("%d", &option);
        switch (option){
        case 0:
            printf("\nSaindo...\n");
            break;

        case 1:
            questao1();
            break;

        case 2:
            questao2();
            break;

        case 3:
            questao3();
            break;

        case 4:
            questao4();
            break;

        case 5:
            questao5();
            break;

        case 6:
            questao6();
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    }while(option != 0);

    return 0;
}