
void questao6(){
    char *string = malloc(60 * sizeof(char));
    if(string == NULL){
        printf("\nErro ao alocar memoria!");
        return;
    }

    printf("\nDigite uma frase: ");
    getchar();
    fgets(string, 60, stdin);

    printf("A frase por palavras e: \n");
    char *separando = strtok(string, " "); 
    while (separando != NULL) {
        printf("\n%s", separando);
        separando = strtok(NULL, " ");
    }

    free(string);
    free(separando);
}