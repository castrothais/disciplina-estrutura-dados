#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void preencherMatriz(int **matriz, int tamanhoMatriz) {
    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz; j++) {
            matriz[i][j] = rand() % 100; // Preenche a matriz com n�meros aleat�rios
        }
    }
}

void imprimirMatriz(int **matriz, int tamanhoMatriz) {
    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void transporMatriz(int **matriz, int tamanhoMatriz) {
    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = i + 1; j < tamanhoMatriz; j++) {
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int **matriz, i, j;
    int tamanhoMatriz;


    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &tamanhoMatriz);


    matriz = malloc(sizeof(int*) * tamanhoMatriz);
    if (matriz == NULL) {
        printf("Erro ao alocar mem�ria para as linhas! \n");
        return 1;
    }


    for (i = 0; i < tamanhoMatriz; i++) {
        matriz[i] = malloc(sizeof(int) * tamanhoMatriz);
        if (matriz[i] == NULL) {
            printf("Erro ao alocar mem�ria para a linha %d! \n", i);
            return 1;
        }
    }

    printf("O tamanho da matriz quadrada � de %d X %d \n\n", tamanhoMatriz, tamanhoMatriz);

    // Semente para n�meros aleat�rios
    srand(time(NULL));


    printf("Matriz preenchida:\n");
    preencherMatriz(matriz, tamanhoMatriz);
    imprimirMatriz(matriz, tamanhoMatriz);


    printf("A matriz transposta �:\n");
    transporMatriz(matriz, tamanhoMatriz);
    imprimirMatriz(matriz, tamanhoMatriz);


    for (i = 0; i < tamanhoMatriz; i++) {
        free(matriz[i]);
    }


    free(matriz);

    return 0;
}
