#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 5
int topo=0;
int tamanho=0;
int pilha[MAX];


void push(int i) {
    if(topo < MAX) {
        pilha[topo] = i;
        topo++;
        tamanho++;
    } else {
        printf("A pilha está cheia! Não é possível inserir nenhum elemento!");
    }
}

int pop(void) {
    if(topo > 0) {
        topo--;
        tamanho--;
        return pilha[topo];
    } else {
        printf("\nNão há elementos para serem removidos!");
        return -1;
    }

}

int getTamanho() {
    return tamanho;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

push(1);
push(2);
push(3);
push(4);


printf("\nTamanho: %d",getTamanho());
printf("\n%d",pop());
printf("\n%d",pop());
printf("\n%d",pop());
printf("\nTamanho: %d",getTamanho());
printf("\n%d",pop());
printf("\n%d",pop());
printf("\nTamanho: %d",getTamanho());

return 0;
}
