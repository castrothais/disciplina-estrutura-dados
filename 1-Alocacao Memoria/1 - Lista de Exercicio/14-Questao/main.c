#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QUANTIDADENUMEROS 10000
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int *inteiros;
    inteiros = (int*)malloc(sizeof(int)*QUANTIDADENUMEROS);

    if(inteiros == NULL) {
       printf("Mem�ria Insuficeinte!");
        return 1;
    } else {
    printf("Aloca��o bem sucedida! \n");
    printf("Primeiro endere�o alocado: %p \n", inteiros);
    printf("�ltimo endere�o alocado: %p \n", inteiros+QUANTIDADENUMEROS-1);
    }

    free(inteiros);
    return 0;
}
