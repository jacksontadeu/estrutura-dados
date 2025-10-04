#include <stdio.h>
#include <stdlib.h>


struct celula{
    int conteudo;
    struct celula *seg;
};
typedef struct celula celula;

celula* inserir(celula* lista, int valor){
    celula *nova = (celula*) malloc(sizeof(celula));

    nova->conteudo =valor;
    nova->seg=lista;

    return nova;
};
void imprimir(celula* lista){
    celula *aux = lista;
    while(aux !=NULL){
        printf("%d ", aux->conteudo);
        aux = aux->seg;

    }
}


void main( ){

    celula* lista=NULL;
    lista = inserir(lista, 10);
    lista = inserir(lista, 15);
    lista = inserir(lista, 19);
    imprimir(lista);

    celula* lista1 =NULL;
    printf("\n");
    lista1 = inserir(lista1,100);
    lista1 = inserir(lista1,150);
    lista1 = inserir(lista1,190);
    lista1 = inserir(lista1,190);
    imprimir(lista1);

    printf("\n");
    celula *aux = lista;
    while(aux->seg !=NULL){
        aux = aux->seg;
       
    };
    aux->seg= lista1;
    imprimir(lista);



}