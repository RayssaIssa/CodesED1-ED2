
void questao5(){
    char *string = malloc(50 * sizeof(char));
    if(string == NULL){
        printf("\nErro ao alocar memoria!");
        return;
    }

    printf("\nDigite uma frase: ");
    getchar();
    fgets(string, 50, stdin);

    int tamanho = strlen(string);
    if (tamanho > 0 && string[tamanho - 1] == '\n') {
        string[tamanho - 1] = '\0';
        tamanho--; 
    }

    printf("A frase e: '%s' com %d caracteres.\n", string, tamanho);

    free(string);
}