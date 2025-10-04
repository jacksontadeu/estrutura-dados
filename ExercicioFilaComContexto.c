#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pessoa{
    char nome[30];
    int idade;
    struct pessoa *seg;
}pessoa;
//typedef struct pessoa pessoa;

struct celula{
    struct pessoa dados;
    struct celula* prox;    
};
typedef struct celula celula;

void inserir(celula **inicio,celula **fim, struct pessoa p){
    celula* nova;
    nova = malloc(sizeof(celula));
    nova->dados = p;
    nova->prox = NULL;
    if(*fim==NULL){
        *fim = *inicio = nova;
    }else{
        (*fim)->prox = nova;
        *fim=nova;
    }
}
void imprimir(celula *inicio){
    celula* imprimir = inicio;
    while(imprimir !=NULL){
        printf("%s %d anos\n", imprimir->dados.nome, imprimir->dados.idade);
        imprimir = imprimir->prox;

    }
}

pessoa remover(celula** inicio, celula** fim){
    celula* aux;
    pessoa p;
    aux = *inicio;
    
    p = aux->dados;

    *inicio = aux->prox;
    free(aux);

    return p;

}


void main(){

    celula* inicio;
    celula* fim;
    inicio=fim=NULL;

    pessoa p;
    p.idade = 30;
    strcpy(p.nome, "Maria");

     pessoa p1;
    p1.idade = 30;
    strcpy(p1.nome, "Ana");

     pessoa p2;
    p2.idade = 30;
    strcpy(p2.nome, "Beatriz");

    pessoa p3;
    p3.idade = 25;
    strcpy(p3.nome, "Carlos");

    pessoa p4;
    p4.idade = 28;
    strcpy(p4.nome, "Fernanda");

    pessoa p5;
    p5.idade = 32;
    strcpy(p5.nome, "Joao");

    pessoa p6;
    p6.idade = 27;
    strcpy(p6.nome, "Patricia");

    pessoa p7;
    p7.idade = 35;
    strcpy(p7.nome, "Lucas");

    pessoa p8;
    p8.idade = 29;
    strcpy(p8.nome, "Juliana");

    pessoa p9;
    p9.idade = 31;
    strcpy(p9.nome, "Rafael");

    pessoa p10;
    p10.idade = 26;
    strcpy(p10.nome, "Gabriela");

    pessoa p11;
    p11.idade = 33;
    strcpy(p11.nome, "Eduardo");

    pessoa p12;
    p12.idade = 24;
    strcpy(p12.nome, "Sofia");

    pessoa p13;
    p13.idade = 49;
    strcpy(p13.nome, "Jackson");
    pessoa p14;
    p14.idade=20;
    strcpy(p14.nome, "Caue");

    inserir(&inicio, &fim, p3);
    inserir(&inicio, &fim, p4);
    inserir(&inicio, &fim, p5);
    inserir(&inicio, &fim, p6);
    inserir(&inicio, &fim, p7);
    inserir(&inicio, &fim, p8);
    inserir(&inicio, &fim, p9);
    inserir(&inicio, &fim, p10);
    inserir(&inicio, &fim, p11);
    inserir(&inicio, &fim, p12);
    inserir(&inicio,&fim,p);
    inserir(&inicio,&fim,p1);
    inserir(&inicio,&fim,p2);
    inserir(&inicio,&fim,p13);
    inserir(&inicio,&fim,p14);

     printf("Fila de atendimento do Supermercado Tabajara: \n");
    
    imprimir(inicio);
     printf("\n");

    printf("Primeira pessoa atendida da fila: \n");
    
    pessoa removida = remover(&inicio, &fim);
    printf("%s %d anos\n", removida.nome, removida.idade);
    printf("\n");

    printf("Nova fila \n");
    imprimir(inicio);

}


