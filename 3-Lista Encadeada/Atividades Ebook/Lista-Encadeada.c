#include <stdio.h>
#include<stdlib.h>
#include<locale.h>

struct EstruturaAluno {
    int matricula;
    char *nome;
    float nota;

    struct EstruturaAluno *proximo;
};

typedef struct EstruturaAluno Aluno;

Aluno *insereInicio(Aluno *atual, Aluno no) {

    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));

    if(novo == NULL) {
        printf("Erro ao alocar mem�ria!");
    } else {
        novo->matricula = no.matricula;
        novo->nome = no.nome;
        novo->nota = no.nota;

        if(atual == NULL) {
            novo->proximo = NULL;
        } else {
           novo->proximo = atual;
        }
    }
    return novo;
}

void imprimirLista(Aluno *atual) {

    if(atual == NULL) {
        printf("A LISTA EST� VAZIA!");
    }

    printf("\n\n---------IN�CIO DA LISTA---------\n");
    while(atual!=NULL) {
        printf("\nMatricula: %d", atual->matricula);
        printf("\tNome: %s", atual->nome);
        printf("\tNota: %.2f\n", atual->nota);
        atual = atual->proximo;
    }
    printf("\n----------FIM DA LISTA----------\n\n");
}

Aluno *insereFinal(Aluno *atual, Aluno no) {
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    Aluno *aux;

    if(novo ==NULL) {
        printf("Erro ao alocar mem�ria!");
    }
        novo->matricula = no.matricula;
        novo->nome = no.nome;
        novo->nota = no.nota;
        novo->proximo = NULL;

        if(atual == NULL) { // Preciso verificar primeiro se a fila est� vazia, se estiver, ele sera o primeiro
            novo->proximo = NULL;
        }
        else {
            aux = atual;
            while(aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    return atual; // Aqui retornou o n� atual, que no caso � o primeiro, pois o novo n� foi inserido na �ltima posi��o
}

Aluno *buscarMatricula(Aluno *atual, int matricula) {
    Aluno *aux;
    aux = atual;
    while(aux != NULL) {
        if(aux ->matricula == matricula) {
                printf("\nAluno Encontrado:");
                printf("\tMatricula: %d", aux->matricula);
                printf("\tNome: %s", aux->nome);
                printf("\tNota: %f", aux->nota);
            return aux;
        }
        aux = aux->proximo;
    }

printf("\nErro ao localizar matr�cula!");
}

Aluno *removerInicio(Aluno *atual) {
    if (atual == NULL) {
        printf("A lista est� vazia!\n");
        return NULL;
    }

    Aluno *novoInicio = atual->proximo;
    free(atual);

    return novoInicio;
}


//Aluno *remove(Aluno *atual, int matricula);

int main() {

    setlocale(LC_ALL,"Portuguese");

    Aluno *listaAluno = NULL;

    Aluno no;
    no.matricula = 111;
    no.nome = "Flavio";
    no.nota = 10.0;

  listaAluno = insereInicio(listaAluno, no);
  imprimirLista(listaAluno);

    Aluno no2;
    no2.matricula = 321;
    no2.nome = "Tatiana";
    no2.nota = 5.6;

    Aluno no3;
    no3.matricula = 748;
    no3.nome = "Jos�";
    no3.nota = 8.9;

  listaAluno = insereFinal(listaAluno,no2);
  imprimirLista(listaAluno);

  buscarMatricula(listaAluno, no.matricula);



  printf("\n ______REMOVENDO NO IN�CIO:______");
  listaAluno = removerInicio(listaAluno);
  imprimirLista(listaAluno);


return 0;
}
