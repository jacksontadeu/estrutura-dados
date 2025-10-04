#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

Node* insere(Node* lista, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return lista;
    }
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}
int main(void){
    Node* lista = NULL;
    //lista = insere(lista, 10);
   // lista = insere(lista, 20);
    lista = insere(lista, 30);

    Node* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");

    // Liberar memória
    while (lista != NULL) {
        Node* temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}