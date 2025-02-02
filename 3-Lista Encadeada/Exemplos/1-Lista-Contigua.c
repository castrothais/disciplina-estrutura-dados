#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 5

int main()
{
setlocale(LC_ALL, "Portuguese");

    float *listaNotas = (float*) malloc(sizeof(float) * MAX);

    float media=0;
    int i;

    for (i = 0; i < MAX; i++)
    {
        printf("\nInforme a %da. nota: ", i+1);
        scanf("%f", listaNotas + i);
        media += *(listaNotas + i);
    }

    printf("\nMedia das notas: %f\n", (media/MAX));
}

// Trata-se de uma simples manipulação de vetor, no qual, os seus elementos estão armazenados em posições
// contíguas na memória.
