#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TOTALVENDAS 4


float calcularFaturamentoTotal(float *vendas) {
    float faturamentoTotal = 0;
    for (int j = 0; j < TOTALVENDAS; j++) {
        faturamentoTotal += *(vendas + j);
    }
    return faturamentoTotal;
}

int main() {

    setlocale(LC_ALL, "Portuguese");


    float *vendas;
    vendas = (float*)malloc(sizeof(float) * TOTALVENDAS);

    if (vendas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }


    printf("Olá, seja bem-vindo! Informe suas vendas e verifique a quantidade total:\n");
    for (int i = 0; i < TOTALVENDAS; i++) {
        printf("Venda %d: ", i + 1);
        scanf("%f", &vendas[i]);
    }

    printf("Faturamento total: R$ %.2f.\n", calcularFaturamentoTotal(vendas));
    free(vendas);
    return 0;
}
