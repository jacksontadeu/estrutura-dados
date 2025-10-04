#include <stdio.h>
#include <stdlib.h>

//cria a estrutura da celula com o conteudo eo ponteiro da proxima scelula
struct celula{
    int conteudo;
    struct celula *seg;
};
typedef struct celula celula;


//funcao que insere uma celular no comeco da lista recebendo uma lista e um valor
celula* inserirnocomecodalista(celula* lista, int valor){
    // cria a celula nova a ser inserida
    celula *nova = (celula*)malloc(sizeof(celula));
    //celular nova no campo conteudo recebe o valor informado no parametro
    nova->conteudo = valor;
    // a celula nova no seguinte recebe a propria lista
    nova->seg = lista;
    //retorna a celula nova no inicio da lista.
    return nova;
};

// funcao que insere no meio da lista na verdade no segundo item da lista
celula* inserirnomeiodalista(celula* lista, int valor){
    //cria a celula nova a ser inserida
    celula* nova = (celula*)malloc(sizeof(celula));
    //celula nova no campo conteudo recebe o valor informado como parametro
    nova->conteudo=valor;
    //celula nova no campo seguinte recebe o ponteiro da lista no campo seguinte 
    nova->seg = lista->seg;
    //lista no campo seguinte recebe a celula nova alocando em segundo na lista
    lista->seg=nova;
    return lista;
};


int main(){

    celula* lista= NULL;
    lista = inserirnocomecodalista(lista, 15);
    lista= inserirnocomecodalista(lista, 30);
    lista= inserirnomeiodalista(lista,20);
    lista = inserirnomeiodalista(lista, 40);
    lista = inserirnomeiodalista(lista, 25);

    celula* aux = lista;
    while(aux !=NULL){
        printf("%d ",aux->conteudo);
        aux= aux->seg;


    }
    return 0;

}