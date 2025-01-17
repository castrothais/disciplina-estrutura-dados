#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");

    int *numero = (int*)malloc(sizeof(int));
    int fatorial = 1;

    if(numero == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        return 1;
    }

    printf("Digite o n�mero para encontrar o fatorial: \n");
    scanf("%d", numero);

    printf("O n�mero informado foi: %d\n", *numero);


    for(int i = *numero; i >= 1; i--){
        fatorial *= i;
    }

    printf(" O fatorial � %d", fatorial);

    return 0;
}
