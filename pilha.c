#include <stdio.h>
#include <stdlib.h>

//cria estrutura da celula
typedef struct cel{
    int conteudo;
    struct cel *seg;
}celula;

void empilha(celula* p, int valor){
    //cria nova celular e aloca memoria
    celula* nova;
    nova = malloc(sizeof(celula));
    //atribui o valor para a celula nova
    nova->conteudo = valor;
    //atribui o campo seg para nova que eh o endereco de p seg
    nova->seg = p->seg;
    //no endereco p seg aloca a celula nova
    p->seg = nova;

}
int desempilha(celula* p){
    //cria a variavel valor
    int valor;
    //cria uma celula temporaria
    celula *q;
    //atribui a celula q o endereco do primeiro elemento da pilha
    q = p->seg;
    //valor recebe o valor de q topo da pilha
    valor = q->conteudo;
    //ponteiro do topo aponta para o proximo elementa da pilha
    p->seg=q->seg;
    //elimina a celula q temporaria
    free(q);
    //retorna o valor
    return valor;
}
void imprime(celula* p){
    celula* aux;
    aux = p->seg;
    printf("Pilha:");
    while(aux != NULL){
        printf(" %d ", aux->conteudo);
        aux=aux->seg;
    }
}


void main(){
    celula topo;
    celula* p;
    p = &topo;
    p->seg= NULL;

    empilha(p, 15);
    empilha(p,20);
    celula *aux = p->seg;
    imprime(p);
    printf("\n");
    printf("Valor desempilhado %d \n",desempilha(p));
    
    imprime(p);
    system("pause");
    

    imprime(p);

    
}