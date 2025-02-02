#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int imprimir_sequencia(int contador, int n) {
    if(contador <= n) {
        printf("%d ", contador);
    return imprimir_sequencia(contador+2, n);
    }
}

int main()
{
    int n;
    setlocale(LC_ALL,"Portuguese");


    printf("Digite um número para descobrir os ímpares até n: ");
    scanf("%d", &n);

    imprimir_sequencia(1, n);


    return 0;
}
