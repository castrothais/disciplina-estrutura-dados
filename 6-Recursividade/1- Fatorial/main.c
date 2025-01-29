#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void verificarNumero(int numero) {
    if(numero>=0){
        if(numero == 0) {
            printf("O fatorial de %d � 1!", numero);
        }
        if(numero == 1) {
            printf("O fatorial de %d � 1!", numero);
        }
        printf("%d", calcularFatorial(numero));

    } else {
        printf("N�mero inv�lido!");
    }
}

int calcularFatorial(int numero) {
    if(numero == 1) {
        return 1;
    }

    return numero * calcularFatorial(numero-1);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int numero;

    printf("Ol�, informe um n�mero para saber o fatorial: ");
    scanf("%d", &numero);

    // Verificar se o n�mero � positivo
    verificarNumero(numero);

}
