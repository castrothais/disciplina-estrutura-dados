#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void preencherMatriz(int **matriz, int **matriz2, int tamanhoMatriz) {
    for(int i = 0; i < tamanhoMatriz; i++){
        for(int j = 0; j < tamanhoMatriz; j++) {
            matriz[i][j] = rand()%10;
            matriz2[i][j] = rand()%10;
        }
    }
}

void imprimirMatriz(int **matriz, int tamanhomatriz){
    for(int i = 0; i < tamanhomatriz; i++) {
        for(int j = 0; j < tamanhomatriz; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void produtodeMatrizes(int **matriz1, int **matriz2, int **matrizResultante, int tamanhoMatriz) {
    for(int i = 0; i < tamanhoMatriz; i++) {
        for(int j = 0; j < tamanhoMatriz; j++) {
                int produtoValores = 0;
            for(int k = 0; k < tamanhoMatriz; k++) {
                produtoValores += matriz1[i][k] * matriz2[k][j];
            }
         matrizResultante[i][j] = produtoValores;
         printf("%d ", matrizResultante[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int **matriz,**matriz2,**matrizResultanteProduto, i, j;
    int tamanhoMatriz;


    printf("Digite o tamanho da matriz:");
    scanf("%d", &tamanhoMatriz);


    matriz = malloc(sizeof(int*) * tamanhoMatriz);
    matriz2 = malloc(sizeof(int*) * tamanhoMatriz);
    matrizResultanteProduto = malloc(sizeof(int*) * tamanhoMatriz);

    if(matriz == NULL || matriz2== NULL || matrizResultanteProduto == NULL) {
        printf("Erro ao alocar memória para as linhas!\n");
        return 1;
        }

    for(int i = 0; i < tamanhoMatriz; i++) {
        matriz[i] = malloc(sizeof(int) * tamanhoMatriz);
        matriz2[i] = malloc(sizeof(int) * tamanhoMatriz);
        matrizResultanteProduto[i] = malloc(sizeof(int) * tamanhoMatriz);
        if(matriz[i] == NULL || matriz2[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d", i);
            return 1;
        }
    }

    srand(time(NULL));

    printf("Matrizes Preenchidas com números aleatórios de 0 até 9:\n");
    preencherMatriz(matriz, matriz2, tamanhoMatriz);


    printf("Matriz 1 preenchida:\n");
    imprimirMatriz(matriz,tamanhoMatriz);

    printf("Matriz 2 preenchida:\n");
    imprimirMatriz(matriz2,tamanhoMatriz);

    printf("Produto das Matriz1 e Matriz2:\n");
    produtodeMatrizes(matriz, matriz2, matrizResultanteProduto, tamanhoMatriz);


    for(int i = 0; i < tamanhoMatriz; i++) {
        free(matriz[i]);
        free(matriz2[i]);
        free(matrizResultanteProduto[i]);
    }


    free(matriz);
    free(matriz2);
    free(matrizResultanteProduto);

    return 0;


}
