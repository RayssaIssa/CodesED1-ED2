
typedef struct FILA{
    int numero[TAM];
    int inicio, fim;
} fila;

void inicializa(fila *f){
    f->inicio = 0;
    f->fim = -1;
}

void adiciona(fila *f, int valor){
    if(f->fim == TAM-1){
        printf("\nFila cheia");
    }else{
        f->fim++;
        f->numero[f->fim] = valor;
    }
}

void remove(fila *f){
    if(f->inicio > f->fim){
        printf("\nFila vazia");
    }else{
        f->inicio++;
    }
}