
void questao2(){
    int a, b, c;
    int *d = &a, *e = &b, *f = &c;

    printf("\nInsira 3 numeros separados por espaco: ");
    scanf("%d %d %d", d, e, f);

    int maior = *d, medio = *d, menor = *d;
    if(*e > *d && *e > *f){
        maior = *e;
        if(*d < *f){
            medio = *f;
            menor = *d;
        }else{
            medio = *d;
            menor = *f;
        }
    }else if(*d > *f && *d > *e){
        maior = *d;
        if(*f > *e){
            medio = *f;
            menor = *e;
        }else{
            medio = *e;
            menor = *f;
        }
    }else if(*f > *d && *f > *e){
        maior = *f;
        if (*d > *e){
            medio = *d;
            menor = *e;
        }else{
            medio = *e;
            menor = *d;
        }        
    }
    printf("\nOrdem Crescente: %d, %d, %d.\nEndereco: %p %p %p\n", menor, medio, maior, &menor, &medio, &maior);
}