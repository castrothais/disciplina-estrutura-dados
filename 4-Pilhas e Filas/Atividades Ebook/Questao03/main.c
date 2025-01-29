#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

struct TipoPilha{
int info;
struct TipoPilha *prox;
};

typedef struct TipoPilha Pilha;


// inserção de um elemento no topo da pilha
Pilha *insere(Pilha *atual, int v) {
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));

    if(novo == NULL) {
        printf("\nErro ao alocar memória!\n");
    } else {
        novo->info = v;
        novo->prox = atual;
        return novo;
    }
}

// recupera um elemento do topo da pilha.*
Pilha *recupera(Pilha *atual) {
    if(atual == NULL) {
        printf("A pilha está vazia! Não possui elementos para serem removidos!");
    } else {
        Pilha *novo = atual->prox;
        free(atual);
        return novo;
    }
}


// retorna o tamanho da pilha.
int getTamanho(Pilha *atual) {
    int tamanhoPilha = 0;
    Pilha *temp = atual;
    while(temp != NULL) {
        tamanhoPilha++;
        temp = temp->prox;
    }
    return tamanhoPilha;
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    Pilha *pilha = NULL;

    pilha = insere(pilha, 10);
    pilha = insere(pilha, 20);
    pilha = insere(pilha, 30);


    pilha = recupera(pilha);
    pilha = recupera(pilha);


    printf("\nTamanho da pilha: %d\n", getTamanho(pilha));

return 0;
}



