#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAMANHOLISTA 10

int preencherLista(int *lista) {
    for(int i = 0; i < TAMANHOLISTA; i++) {
        *(lista+i) = rand() % TAMANHOLISTA;;
    }
}

void imprimirLista(int *lista) {
    for(int i = 0; i < TAMANHOLISTA; i++) {
        printf("%d ", *(lista + i));
    }
    printf("\n");
}


void bubbleSort(int *lista) {
     int i,j;
 for (i=TAMANHOLISTA-1; i>=1; i--){
    for (j=0; j<i; j++){
        if (lista[j]>lista[j+1]){   // Se o elemento da esquerda for maior que o da direita, ocorre a troca!
            int temp = lista[j];
            lista[j] = lista[j+1];
            lista[j+1] = temp;
            }
        }
    }
}

buscaBinaria() {
}

int main()
{

    setlocale(LC_ALL, "Portuguese");
    int *lista = (int*)malloc(sizeof(int) * TAMANHOLISTA);

    srand(time(NULL));

    if(lista == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    preencherLista(lista);
    printf("Imprimir a lista após gerar numero aleatório na lista e preencher: \n");
    imprimirLista(lista);


    printf("\n");

    printf("Lista após a ordenação: \n");
    bubbleSort(lista);
    imprimirLista(lista);


    free(lista);
    return 0;


}
