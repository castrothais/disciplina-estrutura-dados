#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define QUANTIDADESENHA 8

typedef struct fila{
    int identificador;
    struct Fila *proximo;
}Fila;


Fila *inserir_na_fila(Fila *fila, int id) {
    Fila *novo = (Fila*)malloc(sizeof(Fila));

    if(novo == NULL) {
        printf("Erro ao alocar memória!");
    } else {
        novo->identificador = id;
        novo->proximo = NULL;
        if(fila == NULL) {
            return novo;
        }

        temp = fila;
        while(fila!= NULL) {

        }
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    srand(NULL);

    Fila filaComum1 = NULL;
    Fila filaComum2 = NULL;
    Fila filaPreferencial = NULL;

    for(int i= 0; i< QUANTIDADESENHA; i++) {
        int identificador = rand() % 3 + 1;

       switch(identificador) {

    case 1 :
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        printf("Erro ao gerar senha!");

       }

    }

}
