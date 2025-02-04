#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimirFibonacci(int numero, int termoAnterior, int termoAtual) {
    if (numero == 0) return;

    printf("%d ", termoAtual);


    imprimirFibonacci(numero - 1, termoAtual, termoAnterior + termoAtual);
}

void verificarNumero(int numero) {
    if (numero > 0) {
        printf("Sequ�ncia de Fibonacci at� o %d� termo:\n", numero);
        imprimirFibonacci(numero, 0, 1);
    } else {
        printf("N�mero inv�lido! Informe um n�mero maior do que zero.\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numero;
    printf("Informe o n�mero de termos para calcular a sequ�ncia de Fibonacci:\n");
    scanf("%d", &numero);

    verificarNumero(numero);

    return 0;
}
