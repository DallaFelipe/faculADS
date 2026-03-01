#include <stdio.h>

#define FATOR 10

int main() {
    int numero, resultado;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    resultado = numero * FATOR;

    printf("O resultado de %d multiplicado por %d e: %d\n", numero, FATOR, resultado);

    return 0;
}