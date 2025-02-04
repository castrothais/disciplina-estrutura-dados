#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimir_sequencia(int contador, int n) {
    if (contador <= n) {
        if (contador % 2 == 0) {
            printf("%d ", contador);
        }
        imprimir_sequencia(contador + 1, n);
    }
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    int n;

    printf("Digite um número para descobrir os pares até n: ");
    scanf("%d", &n);

    imprimir_sequencia(1, n);  // começa a contar de 1 até n

    return 0;
}
