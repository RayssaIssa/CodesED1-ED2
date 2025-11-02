
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct produto{
    int id;
    char nome[50];
    int quant;
    float preco;
};

struct produto* produtos = NULL;
int produtosVendidos[100], quantProdVendido[100];  //Lista do id dos produtos vendidos e Lista da quantidade de cada um vendido
int quantProd, i, j, numVendido = 0;  //Quantidade de produtos cadastrados e numero de produtos vendidos

void cadastrarProduto(struct produto** produtos, int* quantProd){
    printf("\nQuantos tipos de produtos deseja cadastrar? ");
    scanf("%d", quantProd);
    
    *produtos = (struct produto*)malloc(sizeof(struct produto) * (*quantProd));

    for(i = 0; i < *quantProd; i++){
        printf("\n\tProduto numero %d\n", i+1);
        printf("\nNome: ");
        scanf("%s", (*produtos)[i].nome);
        printf("\nID: ");
        scanf("%i", &(*produtos)[i].id);
        printf("\nQuantidade: ");
        scanf("%i", &(*produtos)[i].quant);
        printf("\nValor unitario: ");
        scanf("%f", &(*produtos)[i].preco);
    }
}

void imprimirNotaFiscal(struct produto* produtos, int tam){
    float total = 0;
    printf("\n\tNota Fiscal\n---------------------------");

    for(i = 0; i < numVendido; i++){
        for(j = 0; j < tam; j++){
            if(produtosVendidos[i] == produtos[j].id){
                printf("\nProduto: %s\tID: %d\nQuantidade: %d\tValor unitario: R$%.2f\n\n", produtos[j].nome, produtos[j].id, quantProdVendido[i], produtos[j].preco);
                total += (produtos[j].preco * quantProdVendido[i]);
                break;
            }
        }
    }
    printf("Valor total: R$%.2f\n\n", total);
}

bool venderProdutos(struct produto* produtos, int tam){
    int quantidade, id;
    char opc;   //Opcao para continuar as vendas
    printf("\nInsira o Id do produto: ");
    scanf("%d", &id);
    for(i = 0; i < tam; i++){
        if(id == produtos[i].id){   //Se houver o produto com esse id
            printf("\nInsira a quantidade de itens: ");
            scanf("%d", &quantidade);
            if(quantidade <= produtos->quant){   //Se houver estoque maior ou igual a quantidade
                produtosVendidos[numVendido] = id;
                quantProdVendido[numVendido] = quantidade;
                numVendido++;
                produtos[i].quant -= quantidade;  //Remove a quantidade do estoque
                printf("\nDeseja cadastrar mais uma venda? (S - sim, N - nao) ");
                scanf(" %c", &opc);
                if(opc == 'S' || opc == 's'){
                    venderProdutos(produtos, quantProd);
                }
                return true;    //venda feita
            }else{
                printf("\nQuantidade de estoque insuficiente!\n");
                return false;   //Quantidade insuficiente
            }        
        }
    }
    printf("\nProduto nao encontrado!\n");
    return false;
}

void cadastroProdutos(int option){
    quantProd = 0;
    printf("\nBem vindo ao cadastro de produtos!\n");
    do{
        printf("\n\tMenu\n1 - Cadastrar produtos\n2 - Cadastrar venda de produtos\n0 - Sair/Retornar as questoes\n\nDigite sua opcao escolhida: ");
        scanf("%d", &option);
        switch (option){
        case 1:
            cadastrarProduto(&produtos, &quantProd);
            break;

        case 2:
            if (produtos != NULL && quantProd > 0){
                //imprimirNotaFiscal(produtos, quantProd);
                if(venderProdutos(produtos, quantProd)){
                    printf("\nVenda realizada com sucesso!\nImprimindo nota fiscal...\n\n");
                    imprimirNotaFiscal(produtos, quantProd);
                }else{
                    printf("\nNao foi possivel realizar a venda, produto indisponivel ou inexistente!\n\n");
                }
            }else {
                printf("\nNao ha produtos cadastrados!\n");
                return;    
            }    
            break;

        case 0:
            free(produtos);
            break;
        default:
            printf("\nOpcao invalida!");
            break;
        }
    } while (option != 0);
    
}