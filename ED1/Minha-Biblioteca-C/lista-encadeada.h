
typedef struct LISTA{
    int numero;
    struct LISTA *prox;
} *lista;

void exibir(lista l){
    lista aux = l;
    printf("\n\tLista\n");
    while(aux != NULL){
        printf("[%d] ", aux->numero);
        aux = aux->prox;
    }
    printf("\n");
}

lista criarNo(int valor){
    lista novo = (lista) malloc(sizeof(lista));
    if(novo == NULL){
        printf("\nNao foi possivel alocar memoria");
        return NULL;
    }
    novo->numero = valor;
    novo->prox = NULL;
    return novo;
}

lista adicionarNaEsquerda(lista l, lista novo){
    novo->prox = l;
    return novo;
}

lista adicionarNaDireita(lista l, lista novo){
    lista aux = l;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return l;
}

lista adicionarNoMeio(lista l, lista novo, int num){
    lista aux = l;
    while(aux->numero != num){
        aux = aux->prox;
    }
    lista auxFrente = aux->prox;
    aux->prox = novo;
    novo->prox = auxFrente;
    return l;
}

int existeValor(lista l, int num){
    lista aux = l;
    do{
        if(aux->numero == num){
            return 1;
        }
        aux = aux->prox;
    }while(aux != NULL);
    return 0;
}

lista adicionarOnde(lista novo, lista l){
    printf("\nOnde deseja adicionar o valor?\n1 - Inicio\n2 - Fim\n3 - Meio\n");
    int opc;
    scanf("%d", &opc);
    lista retorno = NULL;
    switch (opc){
        case 1:
            retorno = adicionarNaEsquerda(l, novo);
            return retorno;
            break;

        case 2:
            retorno = adicionarNaDireita(l, novo);
            return retorno;
            break;

        case 3:
            exibir(l);
            printf("\nDeseja inserir depois de qual valor? ");
            int num;
            scanf("%d", &num);
            if(existeValor(l, num)){
                retorno = adicionarNoMeio(l, novo, num);
                return retorno;
            }else{
                printf("\nO valor nao existe na lista\n");
                return l;
            }
            break;

        default:
            printf("\nValor invalido\n");
            break;
    }
    return l;
}

lista adicionar(lista l, int valor){
    lista novo = criarNo(valor);
    if(novo == NULL){
        return l;
    }if(l == NULL){
        return novo;
    }
    lista retornar = adicionarOnde(novo, l);
    return retornar;
}

lista removerNaEsquerda(lista l){
    lista aux = l;
    l = l->prox;
    free(aux);
    aux = NULL;
    return l;
}

lista removerNaDireita(lista l){
    if(l->prox == NULL){
        free(l);
        l = NULL;
        return l;
    }
    lista aux = l;
    lista auxFrente = aux->prox;
    while(auxFrente->prox != NULL){
        auxFrente = auxFrente->prox;
        aux = aux->prox;
    }
    free(auxFrente);
    auxFrente = NULL;
    aux->prox = NULL;
    return l;
}

lista removerNoMeio(lista l, int num){
    if(l->prox == NULL){
        free(l);
        l = NULL;
        return l;
    }
    lista aux = l;
    lista auxFrente = aux->prox;
    while(auxFrente != NULL){
        if(auxFrente->numero == num){
            aux->prox = auxFrente->prox;
            free(auxFrente);
            auxFrente = NULL;
            return l;
        }else{
            auxFrente = auxFrente->prox;
            aux = aux->prox;
        }
    }
    return l;
}

lista removerOnde(lista l){
    printf("\nOnde deseja remover o valor?\n1 - Inicio\n2 - Fim\n3 - Meio\n");
    int opc;
    scanf("%d", &opc);
    lista retorno = NULL;
    switch (opc){
        case 1:
            retorno = removerNaEsquerda(l);
            return retorno;
            break;

        case 2:
            retorno = removerNaDireita(l);
            return retorno;
            break;

        case 3:
            exibir(l);
            printf("\nDeseja remover qual valor? ");
            int num;
            scanf("%d", &num);
            if(existeValor(l, num)){
                retorno = removerNoMeio(l, num);
                return retorno;
            }else{
                printf("\nValor inexistente na lista\n");
                return l;
            }
            break;

        default:
            printf("\nValor invalido\n");
            break;
    }
    return l;
}

lista remover(lista l){
    if(l == NULL){
        printf("\nLista vazia\n");
        return l;
    }
    lista remover = removerOnde(l);
    return remover;
}