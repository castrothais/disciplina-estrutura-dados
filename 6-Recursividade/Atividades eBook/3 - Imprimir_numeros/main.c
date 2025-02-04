#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int imprimir_sequencia(int contador, int n) {
    printf("%d ", contador);

    if(contador < n) {
        return imprimir_sequencia(contador+1, n);
    }
}

int main()
{

    setlocale(LC_ALL,"Portuguese");

    int n;

    printf("Digite um número:\n");
    scanf("%d", &n);

    imprimir_sequencia(1, n);
    return 0;
}
