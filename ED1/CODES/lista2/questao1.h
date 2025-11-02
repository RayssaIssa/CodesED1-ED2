
void questao1(){
    int a, b;
    int *c = &a, *d = &b;

    printf("\nInsira dois valores inteiros separados por espaco: ");
    scanf("%d %d", c, d);

    printf("\nVariavel a: %d\tVariavel b: %d\n", *c, *d);
    printf("\nSoma: %d\nSubtracao: %d\nMultiplicacao: %d\nDivisao: %d\n", (*c + *d), (*c - *d), (*c * *d), (*c / *d));

}