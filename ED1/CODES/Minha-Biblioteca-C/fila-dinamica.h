
typedef struct FILA{
    int numero;
    struct FILA *prox;
} *fila;

fila criarItem(int valor){
    fila novo = (fila) malloc(sizeof(struct FILA));
    if(novo == NULL){
        printf("\nNao foi possivel alocar memoria");
        return NULL;
    }else{
        novo->numero = valor;
        novo->prox = NULL;
        return novo;
    }
}

fila adicionar(fila f, int valor){
    fila novo = criarItem(valor);
    if(novo == NULL){
        return f;
    }else if(f == NULL){
        return novo;
    }else{
        fila aux = f;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        return f;
    }
}

fila remover(fila f){
    if(f == NULL){
        printf("\nFila vazia");
        return f;
    }else{
        fila aux = f;
        f = f->prox;
        free(aux);
        aux = NULL;
        return f;
    }
}