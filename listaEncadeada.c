#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//cria a struct pessoa


struct pessoa{
    char nome[30];
    int idade;
    struct Pessoa *prox;
};
typedef struct elemento* Lista;

//cria o elemento da lista
struct elemento{
    struct pessoa dados;
    struct elemento *prox;
};
typedef struct elemento Apontador;

//Cria o ponteiro da lista
Lista *li;

//função para criar a lista
Lista* cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}
//verificar tamanho da lista
int tamanho(Lista *li){
    if (*li == NULL)
        return 0;
    int contador = 0;
    Apontador* aux = *li;
    while (aux != NULL){
        contador++;
        aux = aux->prox;

    }
    return contador;
}
//funcao para inserir no inicio
int insere(Lista* li, struct pessoa p){
    if(li == NULL)
        return 0;
    Apontador* novo = (Apontador*) malloc(sizeof(Apontador));
    if(novo == NULL)
        return 0;
    novo->dados = p;
    novo->prox = (*li);
    *li = novo;
    return 1;
}



int main(void){
    Lista *li = cria_lista();
    printf("Tamanho da lista: %d\n", tamanho(li));

    struct pessoa p;
    p.idade = 20;
    strcpy(p.nome, "Maria");

    struct pessoa p1;
    p1.idade = 20;
    strcpy(p1.nome, "João");
    

    insere(li, p);
    printf("Tamanho da lista: %d\n", tamanho(li));

    insere(li, p1);
    printf("Tamanho da lista: %d\n", tamanho(li));

   while (li != NULL) {
        Apontador* temp = *li;
        printf("Nome: %s, Idade: %d\n", temp->dados.nome, temp->dados.idade);
        *li = (*li)->prox;
    }
   

  
}