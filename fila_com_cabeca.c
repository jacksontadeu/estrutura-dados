#include<stdio.h>
#include<stdlib.h>

//cria a struct fila
typedef struct fila Fila;
struct fila{
    struct elemento *inicio;
    struct elemento *fim;
};

//cria a struct elemento
typedef struct elemento Elemento;
struct elemento{
    int dado;
    struct elemento *prox;
};
// cria o ponteiro pra fila
Fila *fi;

// funcao para criar a fila
Fila* cria_fila()
{
    // cria a alocacao de memoria para a fila
    Fila *fi = (Fila*)malloc(sizeof(Fila));
    //verifica se a fila foi criada
    if(fi != NULL){
        // se a fila foi criada o inicio e o fim recebem null indicando que a fila esta vazia
        fi->inicio = NULL;
        fi->fim = NULL;
    }
}
int inserir(Fila* fi, int valor){
    if (fi ==NULL){
        return 0;
    }else{
        // aloca memoria para o novo elemento
        Elemento *novo = (Elemento*)malloc(sizeof(Elemento));

        // atribui valor no novo elemento no campo dado
        novo-> dado = valor;
        // no campo proximo aponta para null
        novo -> prox = NULL;
        //verifica se o incio da fila eh null
        if(fi-> inicio == NULL){
            // se for null a fila esta vazia ai o inicio e o fim da fila apontam para o mesmo elemento
            fi-> inicio = novo;
            fi-> fim = novo;
            return 1;
        }else{
            //se a fila estiver populada entao o elemento novo vai para o fim da fila
            fi-> fim -> prox = novo;
            fi-> fim = novo;
            return 1;
        }
        
    }
}
int tamanho(Fila *fi){
    //verifica se a fila esta vazia
    if (fi == NULL){
        return 0;
    }else{
        // se nao estiver vazia cria um contador 
        int contador = 0;
        // cria um ponteiro auiliar apontando para o inicio da fila
        Elemento* aux = fi-> inicio;
        //percorre a fila ate o final que vai ser null
        while(aux != NULL){
            contador++;
            aux = aux-> prox;
        }
        // retorna o valor do contador que foi incrementado a cada iteracao
        return contador;
    }
    
  
}

int main(void){
    // chamada da funcao cria_lista
    fi = cria_fila();
    //chamada da funcao inserir
    inserir(fi, 10);
    inserir(fi, 20);
    //chamada da funcao tamanho da fila
    printf("Tamanho %d ", tamanho(fi));
    printf("\n");

    //imprimindo a fila
    while(fi != NULL){
        printf("%d ", fi-> inicio-> dado);
        fi-> inicio = fi-> inicio-> prox;
    }
   
}
