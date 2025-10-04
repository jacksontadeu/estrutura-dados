#include <stdio.h>
#include <stdlib.h>

// funcao que cria a estrutura da celula com o conteudo e o ponteiro da proxima celula
struct celula{
    int conteudo;
    struct celula *seg;

};
typedef struct celula celula;

// funcao para inserir na fila sem cabeca com ponteiro de ponteiro
celula* inserir(celula **inicio, celula **fim, int valor){
    //alocacao da celula nova
    celula *nova;
    nova = (celula*)malloc(sizeof(celula));
    // atribuicao do valor ao campo conteudo da celula nova
    nova->conteudo = valor;
    // atribuicao do campo seguinte da celula nova como NULL
    nova->seg = NULL;
    //verifica se o campo inicio e fim sao nulos
    if(*fim ==NULL){
        //se for null a fila esta vazia assim inicio e fim recebe a celula nova
        *fim = *inicio = nova;
    }else{
        //se nao for nulo o campo fim no campo seguinte recebe a celula nova
        (*fim)->seg = nova;
        *fim = nova;
    }
    //retorna o campo nova
    return nova;
};
//funcao para remover celula da fila recebendo como parametro o ponteiro de ponteiro inicio e fim
int remover(celula **inicio, celula **fim){
    //cria um ponteiro p para manipular os dados
    celula *p;
    //cria a variavel inteira que esta no inicio da fila
    int x;
    //ponteiro p recebe a celula inicio
    p = *inicio;
    //a variavel x recebe p valor que esta em p que eh do inicio
    x = p->conteudo;
    //o ponteiro de inicio recebe o ponteiro seguinte
    *inicio = p->seg;
    //elimina ao ponteiro p criado no inicio da funcao
    free(p);
    //verifica se inicio eh nulo se for fim tambem sera nulo
    if(*inicio == NULL){
        *fim = NULL;
    }
    //retorna  o valor da variavek x se necessario usar em algum lugar
    return x;
};



int main(void){
    // instanciacao da fila como nula ou vazia
    //celula* fila = NULL;
    //criacao do ponteiro inicio da fila
    celula *inicio;
    //criacao do ponteiro fim da fila
    celula *fim;
    //setando os ponteiros como nulos
    inicio = fim = NULL;

    

    //chamada da funcao inserir 
    inserir(&inicio, &fim, 15);
     inserir(&inicio, &fim, 115);
     inserir(&inicio, &fim, 1153);
   inserir(&inicio, &fim, 1);

    


  
    // criacao de m ponteiro temporario para imprimir a fila
    celula *imprimir= inicio;
    //interacao para verificar se o ponteiro imprimir eh nulo
    while(imprimir != NULL){
        //enquanto nao foir nulo imprime o conteudo 
        printf("%d  ", imprimir->conteudo);
        //ponteiro imprimir recebe p ponteiro da celula seguinte
        imprimir = imprimir->seg;
    }
    printf("\nCelula removida ");
    int removida = remover(&inicio, &fim);
    printf("%d ", removida);
    printf("\nNova fila ");

    celula *imprimir1= inicio;
    //interacao para verificar se o ponteiro imprimir eh nulo
    while(imprimir1 != NULL){
        //enquanto nao foir nulo imprime o conteudo 
        printf("%d  ", imprimir1->conteudo);
        //ponteiro imprimir recebe p ponteiro da celula seguinte
        imprimir1 = imprimir1->seg;
    }
}