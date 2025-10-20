#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct livro{
    char nome[30];
    struct livro* seg;
}livro;

typedef struct celula{
    struct livro dados;
    struct celula* seg;
}celula;

void inserirlivro(celula* p, livro li){
    celula* novo;
    novo = malloc(sizeof(celula));

    novo->dados = li;
    novo->seg= p->seg;
    p->seg = novo;
}
void imprime(celula* p){
    celula* aux;
    aux = p->seg;
    system("cls");
    printf("Livros guardados na gaveta: \n");
    if(aux == NULL){
        printf("Gaveta vazia!!!\n");
    }
    while(aux != NULL){
        printf(" %s \n", aux->dados.nome);
        aux=aux->seg;
    }
}
livro remover(celula* p){
    
    livro li;
    celula* temp;
    temp = p->seg;
    li = temp->dados;
    p->seg = temp->seg;
    free(temp);
    return li;
    
    
}

void main(){

    //celula* topo = malloc(sizeof(celula));
    celula topo;
    celula* p;
    p = &topo;
    p->seg= NULL;
    livro removido;
    char opcao;
    char continua;
    system("cls");
    printf("Abrindo a gaveta para guardar os livros \n");
    system("pause");

    livro l1;
    strcpy(l1.nome,"Algoritmo");

    livro l2;
    strcpy(l2.nome,"Java Arte de Programar");

    livro l3;
    strcpy(l3.nome,"Estrutura de Dados em C");

    inserirlivro(p, l1);
    inserirlivro(p, l2);
    inserirlivro(p, l3);
    system("cls");
    printf("Guardando os livros \n");
    
    system("pause");
    

    imprime(p);
    system("pause");
    do{
        printf("Deseja remover um livro (s/n): ");
        scanf ("%c", &opcao);
        switch(opcao){
            case 's':
         removido = remover(p);
         system("cls");
         printf("Livro removido: %s \n", removido.nome);
         system("pause");
         break;
         case 'n':
         break;
            default:
            printf("opcao invalida \n");
        }
        imprime(p);
        
    }while(opcao !='n');

}
    
