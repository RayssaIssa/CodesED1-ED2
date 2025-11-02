#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "questao7.h"
#include "questao6.h"
#include "questao5.h"
#include "questao4.h"
#include "questao2e3.h"
#include "questao1.h"


int main(){
    int option = 100;

    do{
        printf("\n\tLista 1 de Estruturas de Dados 1 - by rayssa\n\n");
        printf("\n\tMenu\n\n1 - TAD da contaBancaria, \n2 e 3 - Registro Salario, \n4 - Cadastro de alunos, \n5 - TAD para vetores, \n6 - Cadastro de produtos, \n7 - Registro estudantes e funcionarios, \n0 - Encerrar programa\n\nEscolha a questao: ");
        scanf("%d", &option);

        switch (option){
        case 0:
            printf("\nEncerrar programa...\n");
            break;        
        case 1:
            printf("\n\t--- Questao 1 ---\n");
            iniciarConta(option);
            break;
        case 2:
            printf("\n\t--- Questao 2 e 3 ---\n");
            regfunction(option);
            break;
        case 3:
            printf("\n\t--- Questao 3 ---\n");
            regfunction(option);
            break;
        case 4:
            printf("\n\t--- Questao 4 ---\n");
            questao4(option);
            break;
        case 5:
            printf("\n\t--- Questao 5 ---\n");
            questao5(option);
            break;
        case 6:
            printf("\n\t--- Questao 6 ---\n");
            cadastroProdutos(option);
            break;
        case 7:
            printf("\n\t--- Questao 7 ---\n");
            isereNomes(option);
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }

    } while (option != 0);
    
    return 0;
}