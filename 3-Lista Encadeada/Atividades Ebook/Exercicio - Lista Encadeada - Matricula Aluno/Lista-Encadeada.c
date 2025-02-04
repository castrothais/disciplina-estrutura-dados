#include <stdio.h>
#include<stdlib.h>
#include<locale.h>

struct EstruturaAluno {
    int matricula;
    char *nome;
    float nota;

    struct EstruturaAluno *proximo;
};

int tamanhoLista = 0;

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
    tamanhoLista++;
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
    tamanhoLista ++;
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

    tamanhoLista--;
    return novoInicio;
}

Aluno *removerFinal(Aluno *atual) {
  Aluno *aux;

  if(atual == NULL) {
    printf("A lista est� vazia!");
    return NULL;
  }

  if(atual->proximo == NULL) {
    free(atual);
    return NULL;
  }

  aux = atual;

  while(aux->proximo->proximo != NULL) {
    aux = aux->proximo;
  }

  free(aux->proximo);
  aux->proximo = NULL;

  tamanhoLista--;
  return atual;

}

Aluno *removeAlunoMatriculado(Aluno *atual, int matricula) {
    if (atual == NULL) {
        printf("A lista est� vazia!\n");
        return NULL;
    }


    if (atual->matricula == matricula) {
        Aluno *temp = atual;
        atual = atual->proximo;
        free(temp);
        return atual;
    }

    Aluno *aux = atual;
    while (aux->proximo != NULL && aux->proximo->matricula != matricula) {
        aux = aux->proximo;
    }

    if (aux->proximo != NULL) {
        Aluno *temp = aux->proximo;
        aux->proximo = aux->proximo->proximo;
        free(temp);
    } else {
        printf("Matr�cula %d n�o encontrada na lista!\n", matricula);
    }
    tamanhoLista--;
    return atual;
}

float calcularMedia(Aluno *atual) {
    float somaNotas = atual->nota;
    if(atual == NULL) {
        printf("A lista est� vazia!");
        return;
    }
    while(atual->proximo != NULL) {
        somaNotas += atual->proximo->nota;
        atual = atual->proximo;
    }
    return somaNotas/tamanhoLista;
}


int main() {

    setlocale(LC_ALL,"Portuguese");

    Aluno *listaAluno = NULL;

    Aluno no;
    no.matricula = 111;
    no.nome = "Flavio";
    no.nota = 10.0;

    Aluno no2;
    no2.matricula = 321;
    no2.nome = "Tatiana";
    no2.nota = 5.6;

    Aluno no3;
    no3.matricula = 748;
    no3.nome = "Jos�";
    no3.nota = 8.9;

  // INSERIR NO INICIO DA LISTA
  listaAluno = insereInicio(listaAluno, no);
  imprimirLista(listaAluno);
  printf("\nTAMANHO DA LISTA: %d", tamanhoLista);

  // INSERIR NO FINAL DA LISTA
  listaAluno = insereFinal(listaAluno,no2);
  imprimirLista(listaAluno);

  printf("%.2f", calcularMedia(listaAluno));

  // REMOVENDO INICIO DA LISTA
  listaAluno = removerInicio(listaAluno);
  imprimirLista(listaAluno);

  // REMOVENDO FINAL DA LISTA
  listaAluno = removerFinal(listaAluno);
  imprimirLista(listaAluno);

  // BUSCAR ATRAV�S DA MATRICULA
  buscarMatricula(listaAluno, no.matricula);

  // REMOVENDO ATRAV�S DA MATR�CULA
  listaAluno = removeAlunoMatriculado(listaAluno, 111);
  imprimirLista(listaAluno);


return 0;
}
