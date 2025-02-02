#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 3

// Trata-se de uma lista linear por contiguidade de elementos compostos(struct). Na qual, cada nó
// armazena a matrícula, nome e a nota do aluno. O objetivo do programa é descobrir quais alunos alcaçaram a nota superior
// ou igual à média da turma.

struct EstruturaAluno
{
    int matricula;
    char *nome;
    float nota;
};

typedef struct EstruturaAluno Aluno;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Aluno *listaAlunos = (Aluno*) malloc(sizeof(Aluno) * MAX);

    int i;
    float media = 0;

    for (i = 0; i < MAX; i++)
    {
        printf("\nInforme a matricula do aluno: ");
        scanf("%d", &((listaAlunos+i)->matricula));

        (listaAlunos+i)->nome = (char *) malloc(sizeof(char) * 30);
        printf("\nInforme o nome do aluno: ");
        scanf("%s",(listaAlunos+i)->nome);

        printf("\nInforme a nota do aluno: ");
        scanf("%f", &((listaAlunos+i)->nota));

        media += (listaAlunos+i)->nota;
    }

    media = media / MAX;

    printf("\n\nAlunos com nota superior ou igual a média da turma:");
    for (i = 0; i < MAX; i++)
    {
        if ((listaAlunos+i)->nota >= media){
            printf("\n%d - %s", (listaAlunos+i)->matricula, (listaAlunos+i)->nome);
        }
    }
}
