#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TOTALNOTAS 5

float calcularMediaAtleta(int *nota);
float porcentagemAbaixodaMedia(int *nota, float media);
float porcentagemAcimadaMedia(int *nota, float media);
int calcularMelhorNota(int *nota);
int calcularMenorNota(int *nota);


int main() {
    setlocale(LC_ALL, "Portuguese");

    int *nota;
    nota = (int*)malloc(sizeof(int) * TOTALNOTAS);

    if (nota == NULL) {
        printf("Memória Insuficiente!\n");
        return 1;
    }

    printf("Informe as notas das Provas: \n");
    for (int i = 0; i < TOTALNOTAS; i++) {
        int notaValida = 0;

        while (notaValida == 0) {
            printf("Nota %d: ", i + 1);
            scanf("%d", &nota[i]);

            if (nota[i] < 0 || nota[i] > 10) {
                printf("A nota deve estar entre 0 e 10! Tente novamente.\n");
            } else {
                notaValida = 1;
            }
        }
    }


    printf("\nNotas informadas:\n");
    for (int i = 0; i < TOTALNOTAS; i++) {
        printf("Nota %d: %d\n", i + 1, nota[i]);
    }

    float media = calcularMediaAtleta(nota);
    printf("\nMédia obtida pelo atleta: %.2f.\n", media);
    printf("\nMelhor nota obtida pelo atleta: %d\n", calcularMelhorNota(nota));
    printf("\nMenor nota obtida pelo atleta: %d\n", calcularMenorNota(nota));
    printf("\nPorcentagem de pontuações acima da média do atleta: %.2f%%\n", porcentagemAcimadaMedia(nota, media));
    printf("\nPorcentagem de pontuações abaixo da média do atleta: %.2f%%\n", porcentagemAbaixodaMedia(nota, media));
    printf("\nQuantidade de Juizes que atribuiram a maior nota: %d \n", numeroJuizesAtribuiramNotaBoa(nota));
    free(nota);
    return 0;
}

float calcularMediaAtleta(int *nota){
    float notaTotal= 0;
    float mediaNota;
    for(int i =0; i< TOTALNOTAS; i++) {
        notaTotal+= *(nota + i);
    }
    mediaNota = notaTotal/TOTALNOTAS;
    return mediaNota;
}

int calcularMelhorNota (int *nota) {
    int maiorNota = 0;
    for(int i = 0; i< TOTALNOTAS; i++) {
        if(*(nota+i) > maiorNota) {
            maiorNota = *(nota+i);
        }
    }
    return maiorNota;
}

int calcularMenorNota (int *nota) {
    int menorNota = *nota;
    for(int i =0; i< TOTALNOTAS; i++) {
        if(*(nota + i) < menorNota) {
            menorNota = *(nota+i);
        }
    }
    return menorNota;
}

float porcentagemAcimadaMedia (int *nota, float media) {
    int somaAcimadaMedia = 0;
for(int i = 0; i<TOTALNOTAS; i++) {
    if(*(nota + i) > media) {
        somaAcimadaMedia ++;
    }
}
return (float)(somaAcimadaMedia * 100) / TOTALNOTAS;
}

float porcentagemAbaixodaMedia (int *nota, float media) {
    int somaAbaixodaMedia = 0;
    for(int i = 0; i<TOTALNOTAS; i++) {
        if(*(nota +i) < media) {
            somaAbaixodaMedia ++;
        }
    }
return (float)(somaAbaixodaMedia * 100) / TOTALNOTAS;
}

int numeroJuizesAtribuiramNotaBoa(int *nota) {
    int quantidade = 0;
    int melhorPontuacao = calcularMelhorNota(nota);

    for(int i = 0; i < TOTALNOTAS; i++)
    {
        if(*(nota + i) == melhorPontuacao)
        {
            quantidade++;
        }
    }
    return quantidade;

}
