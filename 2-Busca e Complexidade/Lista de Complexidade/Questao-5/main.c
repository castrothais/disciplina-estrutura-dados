#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void preencherLista(int *lista, int tamanhoLista) {
    for(int i = 0; i < tamanhoLista; i++) {
        printf("Digite o valor da %dª posição: \n", i+1);
        scanf("%d", lista + i);
    }
}

void imprimirLista(int *lista, int tamanhoLista) {
    for(int i = 0; i < tamanhoLista; i++) {
        printf("%d ",*(lista+i));
    }
}

int somarParesdeNumeros(int *lista, int tamanho, int valorInformado) {
    int valor = valorInformado;
    int quantidadePares = 0;
    for(int i = 0; i < tamanho; i++) {
        for(int j = i + 1; j < tamanho; j++) {
            if(*(lista+i) + *(lista+j) == valor) {
                quantidadePares++;
            }
        }
    }

    return quantidadePares;
}



int main()
{
    setlocale(LC_ALL, "Portuguese");
    int tamanhoLista;
    int valorInformado;

    printf("Digite o tamanho da lista: \n");
    scanf("%d", &tamanhoLista);

    printf("\nO tamanho da lista informado é: %d \n", tamanhoLista);

    int *lista = (int*)malloc(sizeof(int) * tamanhoLista);


    if(lista == NULL) {
        printf("Erro ao alocar memória!");
        return 1;
    }


    printf("\nInforme o valor que deseja verificar para contar quantos pares de números têm soma igual a esse valor:\n");
    scanf("%d", &valorInformado);
    printf("\nO valor informado é: %d\n", valorInformado);


    preencherLista(lista, tamanhoLista);

    printf("\nLista preenchida:\n");
    imprimirLista(lista, tamanhoLista);


    printf("\nO vetor possui %d pares",somarParesdeNumeros(lista, tamanhoLista, valorInformado));

    free(lista);

    return 0;
}
