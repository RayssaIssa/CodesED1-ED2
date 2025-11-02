#include <stdio.h>

typedef struct Pilha{
	char nome[5];
	int topo;
} Pilha;

void pop(Pilha *p){
	if(p->topo == -1){
		printf("\nPilha vazia");
	}else{
		p->topo--;
	}
}

void inverter(Pilha *p){
	Pilha pilha;
	pilha.topo = -1;

	printf("\nPilha original: %s", p->nome);

	while(p->topo != -1){
		pilha.nome[pilha.topo]  = p->nome[p->topo];
        pilha.topo++;
		pop(p);
	}

	printf("\nPilha invertida: %s", pilha.nome);
}

int main(){
	Pilha p;
	printf("\nDigite a string de 5 caracteres: ");
	scanf("%s", p.nome);
	p.topo = 4;
	
	inverter(&p);

	return 0;
}