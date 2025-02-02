#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int multiplicarNumeroSoma(int n1, int n2, int quantidade) {
    if (quantidade == n2) {
        return 0;
    }
    return n1 + multiplicarNumeroSoma(n1, n2, quantidade + 1);
}

void verificarNumero(int n1, int n2) {
    if (n1 == 0 || n2 == 0) {
        printf("Resultado da multiplicação de %d por %d é: 0\n", n1, n2);
        return;
    }

    if (n1 == 1 || n2 == 1) {
        printf("Resultado da multiplicação de %d por %d é: %d\n", n1, n2, n1 * n2);
        return;
    }

    int resultado;
    if (n1 < 0 && n2 < 0) {
        n1 = -n1;
        n2 = -n2;
        resultado = multiplicarNumeroSoma(n1, n2, 0);

    } else {
        resultado = multiplicarNumeroSoma(n1, n2, 0);
    }

    printf("Resultado da multiplicação de %d por %d é: %d\n", n1, n2, resultado);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numero1, numero2;

    printf("Multiplicação utilizando apenas a operação de soma!\n");
    printf("\nInforme o 1º número:\n");
    scanf("%d", &numero1);

    printf("\nInforme o 2º número:\n");
    scanf("%d", &numero2);

    verificarNumero(numero1, numero2);

    return 0;
}
