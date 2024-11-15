#include <stdio.h>
#include <stdlib.h>
include <locale.h>

int main()
{
int *p;
p = (int*) malloc(sizeof(int));
*p=3;

printf("Parte de valor de p: %d", *p);
printf("\nParte de posição de p: %d", p);
}
