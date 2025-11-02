/* Desejamos manipular polinômios do tipo p(x) = a0 + a1x + a2x2 + ... + anxn . Tais polinômios podem ser representados por listas simplesmente encadeadas onde cada nó da lista possui três campos: um para o coeficiente que é um número real, um para o expoente que é um número inteiro e um campo que armazena um ponteiro para o próximo nó. Escreva programas para: ler um polinômio e armazená-lo na lista, somar dois polinômios, multiplicar dois polinômios e derivar um polinômio. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Lista{
    double coeficiente;
    int expoente;
    struct Lista *proximo;
} *lista;

void exibir(lista l){
    printf("\n");
    lista aux = l;
    while(aux != NULL){
        printf(" %.2lf^%d", aux->coeficiente, aux->expoente);
        aux = aux->proximo;
    }
    printf("\n");
}

lista criarItem(double coeficiente, int expoente){
    lista novo = (lista) malloc(sizeof(struct Lista));
    if(novo == NULL){
        return NULL;
    }
    novo->coeficiente = coeficiente;
    novo->expoente = expoente;
    novo->proximo = NULL;
    return novo;
}

lista inserir(lista l, double coe, int exp){
    lista novo = criarItem(coe, exp);
    if(novo == NULL){
        return l;
    }else if(l == NULL){
        return novo;
    }
    lista aux = l;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo;
    return l;
}

int existe(lista l, double coeficiente, int expoente){
    lista aux = l;
    while(aux != NULL){
        if(aux->coeficiente == coeficiente && aux->expoente == expoente){
            return 1;
        }
        aux = aux->proximo;
    }
    return 0;
}

double multiplicar(double coe1, int exp1, double coe2, int exp2){
    double pol1 = pow(coe1, exp1);
    double pol2 = pow(coe2, exp2);
    double resultado = pol1 * pol2;
    return resultado;
}

double somar(double coe1, int exp1, double coe2, int exp2){
    double pol1 = pow(coe1, exp1);
    double pol2 = pow(coe2, exp2);
    double resultado = pol1 + pol2;
    return resultado;
}

lista derivar(double coeficiente, int expoente){
    double polinomio = coeficiente * expoente;
    lista resultado = criarItem(polinomio, expoente-1);
    return resultado;
}

int main(){
    lista polinomios = NULL;
    int opc = 333, expoente, exp2;
    double coeficiente, coe2;
    do{
        printf("\n\tMenu\n0 - Sair\n1 - Inserir polinomio\n2 - Somar dois polinomios\n3 - Multiplicar dois polinomios\n4 - Derivar um polinomio\nEscolha a opcao desejada: ");
        scanf("%d", &opc);
        switch(opc){
            case 0:
                printf("\nSaindo...");
                break;

            case 1:
                printf("\nDigite o coeficiente: ");
                scanf("%lf", &coeficiente);
                printf("\nDigite o expoente: ");
                scanf("%d", &expoente);
                polinomios = inserir(polinomios, coeficiente, expoente);
                exibir(polinomios);
                break;

            case 2:
                exibir(polinomios);
                printf("Escolha o PRIMEIRO polinomio que deseja somar, digite o coeficiente e seguido de um enter o expoente: ");
                scanf("%lf", &coeficiente);
                scanf("%d", &expoente);

                if(existe(polinomios, coeficiente, expoente)){
                    exibir(polinomios);
                    printf("Escolha o SEGUNDO polinomio que deseja somar, digite o coeficiente e seguido de um enter o expoente: ");
                    scanf("%lf", &coe2);
                    scanf("%d", &exp2);

                    if(existe(polinomios, coe2, exp2)){
                        double somado = somar(coeficiente, expoente, coe2, exp2);
                        printf("\nA multiplicacao dos polinomios %.1f^%d e %.1f^%d e igual a: %.2f", coeficiente, expoente, coe2, exp2, somado);
                    }else{
                        printf("\nPolinomio nao encontrado na lista\n");
                    }
                }else{
                    printf("\nPolinomio nao encontrado na lista\n");
                }
                break;

            case 3:
                exibir(polinomios);
                printf("Escolha o PRIMEIRO polinomio que deseja multiplicar, digite o coeficiente e seguido de um enter o expoente: ");
                scanf("%lf", &coeficiente);
                scanf("%d", &expoente);

                if(existe(polinomios, coeficiente, expoente)){
                    exibir(polinomios);
                    printf("Escolha o SEGUNDO polinomio que deseja multiplicar, digite o coeficiente e seguido de um enter o expoente: ");
                    scanf("%lf", &coe2);
                    scanf("%d", &exp2);

                    if(existe(polinomios, coe2, exp2)){
                        double multiplicado = multiplicar(coeficiente, expoente, coe2, exp2);
                        printf("\nA multiplicacao dos polinomios %.1f^%d e %.1f^%d e igual a: %.2f", coeficiente, expoente, coe2, exp2, multiplicado);
                    }else{
                        printf("\nPolinomio nao encontrado na lista\n");
                    }
                }else{
                    printf("\nPolinomio nao encontrado na lista\n");
                }
                break;

            case 4:
                exibir(polinomios);
                printf("Escolha o polinomio que deseja derivar, digite o coeficiente e seguido de um espaço o expoente: ");
                scanf("%lf", &coeficiente);
                scanf("%d", &expoente);
                if(existe(polinomios, coeficiente, expoente)){
                    lista derivado = derivar(coeficiente, expoente);
                    printf("\nA derivacao do polinomio %.1f^%d e: %.1f^%d", coeficiente, expoente, derivado->coeficiente, derivado->expoente);
                    free(derivado);
                }else{
                    printf("\nPolinomio nao encontrado na lista\n");
                }
                break;

            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }while(opc != 0);
    free(polinomios);
    return 0;
}