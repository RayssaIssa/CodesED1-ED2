
// Funções gerais de Pilha estática
#define tam

struct Pilha{
    int topo;
    int pilha[tam];
};

void inicializaPilha(struct Pilha *p){
    p->topo = -1;
}

int pilhaVazia(struct Pilha *p){
    if(p->topo == -1){
        return 1;
    }else{
        return 0;
    }
}

int pilhaCheia(struct Pilha *p, int tamanho){
    if(p->topo == tamanho-1){
        return 1;
    }else{
        return 0;
    }
}

void exibirTopo(struct Pilha *p){
    if(pilhaVazia(p)){
        printf("\nA pilha esta vazia!\n");
    }else{
        printf("\nO valor %d esta no topo %d", p->pilha[p->topo], p->topo);
    }
}

void push(struct Pilha *p, int tamanho, int valor){   //push - inserir elemento na pilha
    if(pilhaCheia(p, tamanho)){
        printf("\nPilha cheia\n");
    }else{
        p->topo++;
        p->pilha[p->topo] = valor;
        printf("\nValor %d inserido na pilha\n", valor);
    }
}

void pop(struct Pilha *p){  //pop - remover elemento da pilha 
    if(pilhaVazia(p)){
        printf("\nPilha vazia\n");
    }else{
        p->topo--;
        printf("\nValor removido da pilha\n");
    }
}

