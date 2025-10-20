#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct cel{
    char valor;
    struct cel *seg;
}celula;

void empilha(celula *p, char valor) {
    celula *nova = malloc(sizeof(celula));
    
    nova->valor = valor;
    nova->seg = p->seg;
    p->seg = nova;
}
char desempilha(celula* p){
    char valor;
    celula *q;
    q = p->seg;
    valor = q->valor;
    p->seg=q->seg;
    free(q);
    return(valor);
   
}

void main(){
    setlocale(LC_ALL,"");
    celula topo;
    celula *p;
    p = &topo;
    p->seg=NULL;
     char str[] = "((){()}){}}}";

    // printf("%c", str[2]);
    char removido;
   int tamanho;
   tamanho = strlen(str);
   printf("%d",tamanho);
   printf("\n");
   //empilha(p, c);
   for(int i =0; i < tamanho; i++){
    char c = str[i];
     if(c== '(' || c=='{'){
        empilha(p,c);
     }else if (c ==')' || c =='}'){
       removido= desempilha(p);
     }
     printf("%c", removido);
     
    }
    printf("\n");
    printf("-----------------------");
    printf("\n");
     celula* aux = p->seg;
      while(aux != NULL){
        if(aux == NULL){
            printf("Pilha vazia");
        }else{
            printf("%c", aux->valor);
            aux =aux->seg;
        }
        
      }
   
}