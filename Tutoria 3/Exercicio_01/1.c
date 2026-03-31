#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Declarar um ponteiro para float
    float *ptr;

    // 2. Alocar memória dinamicamente
    // sizeof(float) garante que estamos alocando o espaço correto (geralmente 4 bytes)
    ptr = (float *) malloc(sizeof(float));

    // Verificar se a alocação foi bem-sucedida
    if (ptr == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // 3. Receber um valor via teclado
    printf("Digite um valor real: ");
    scanf("%f", ptr);

    // 4. Exibir com duas casas decimais
    // O modificador %.2f limita a exibição das casas decimais
    printf("O valor digitado foi: %.2f\n", *ptr);

    // Importante: Sempre liberar a memória alocada
    free(ptr);

    return 0;
}
//O sizeof é fundamental para que o código seja portátil entre diferentes arquiteturas.
//No scanf, usamos ptr diretamente porque ele já guarda o endereço de memória.
//já no printf, usamos *ptr para "encontrar" no endereço e pegar o valor que está guardado l