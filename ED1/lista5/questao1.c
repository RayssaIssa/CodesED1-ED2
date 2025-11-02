/* Digamos que nosso alfabeto contém apenas as letras a, b e c. Qualquer string desse conjunto tem a forma WcM, onde W é uma sequência das letras ab, e M é o inverso de W. Por exemplo: ababcbaba. Escreva um programa que decida se uma determinada string  pertence ou não ao formato WcM. Utilize uma estrutura de pilha para resolver o problema. */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *string; 
    int topo; 
    int tamanhoMaximo; 
} WcM;

int ehWcM(WcM *wcm){
    char *string = wcm->string;
    int i = 0, j;

    // Verificando se contém apenas 'a', 'b' e 'c'
    while (string[i] != '\0') {
        if (string[i] != 'a' && string[i] != 'b' && string[i] != 'c') {
            return 0; // Contém caracteres inválidos
        }
        i++;
    }
    // Encontrar posição do 'c' no meio
    int meio = -1;
    for (j = 0; j < i; j++) {
        if (string[j] == 'c') {
            meio = j;
            break;
        }
    }
    if (meio == -1 || meio * 2 + 1 != i) {
        return 0; // 'c' não encontrado ou não está no meio
    }
    // Verificar se M é o inverso de W
    for (j = 0; j < meio; j++) {
        if (string[j] != string[i - j - 1]) {
            return 0; // Não segue o formato WcM
        }
    }
    return 1; // String válida
}

int main(){
    WcM *wcm = (WcM *)malloc(sizeof(WcM));
    if(wcm == NULL){
        printf("\nErro ao alocar memoria\n");
        free(wcm);
        return 1;
    }
    wcm->tamanhoMaximo = 100; 
    wcm->string = (char *)malloc(wcm->tamanhoMaximo * sizeof(char));
    if (wcm->string == NULL) {
        printf("\nErro ao alocar memoria para a string\n");
        free(wcm);
        return 1;
    }
    
    printf("\nQuestao 1 - Lista 5 - ED 1\n");
    printf("\nDigite a palavra escrita em formato WcM para verificar se ela e valida: ");
    scanf("%99s", wcm->string); 

    if(ehWcM(wcm)){
        printf("\nA string pertence ao formato WcM\n");
    } else {
        printf("\nA string nao pertence ao formato WcM\n");
    }
    free(wcm);
    return 0;
}