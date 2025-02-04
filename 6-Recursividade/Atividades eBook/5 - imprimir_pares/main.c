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

    printf("Digite um n�mero para descobrir os pares at� n: ");
    scanf("%d", &n);

    imprimir_sequencia(1, n);  // come�a a contar de 1 at� n

    return 0;
}
