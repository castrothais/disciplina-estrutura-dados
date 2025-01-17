#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void preencherVetor(int *lista, int n) {
    for(int i = 0; i < n; i++) {
        *(lista+i)= rand() % n;
    }
}

void imprimirVetor(int *lista, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n",*(lista+i));
    }
}

void ordenarListaCrescente(int *lista, int n) {
    for(int i =0; i < n - 1; i ++){
        for(int j = i + 1; j < n; j ++) {
            if(*(lista + i) > *(lista+j)){
                int temporaria = *(lista+i);
                *(lista + i) = *(lista + j);
                *(lista + j) = temporaria;
            }
        }
    }
}


int maiorNumero(int *lista, int n) {
    int maiorNumero = *(lista+0);
    for(int i = 0; i < n; i++) {
        if(*(lista + i) >= maiorNumero) {
            maiorNumero = *(lista+i);
        }
}
return maiorNumero;
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int n;
    int *lista = (int*)malloc(sizeof(int) * n);

    srand(time(NULL));

    if(lista == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite o tamanho da lista: \n");
    scanf("%d", &n);

    preencherVetor(lista, n);

    printf("O vetor gerado é: \n");
    imprimirVetor(lista, n);

    printf("Lista Ordenada de forma crescente: \n");
    ordenarListaCrescente(lista, n);
    imprimirVetor(lista, n);

    printf("O maior número da lista é %d", maiorNumero(lista, n));
    free(lista);
    return 0;
}
