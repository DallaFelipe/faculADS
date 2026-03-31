#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *vetor;
    float soma = 0;

    // 1. Solicitar o tamanho N
    printf("Digite o numero de elementos (N): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    // 2. Alocar o vetor dinamicamente
    // Alocamos (n * tamanho de um inteiro) bytes
    vetor = (int *) malloc(n * sizeof(int));

    // Verificar se a alocação funcionou
    if (vetor == NULL) {
        printf("Erro: Memoria insuficiente!\n");
        return 1;
    }

    // 3. Preencher o vetor e acumular a soma
    for (i = 0; i < n; i++) {
        printf("Digite o valor para a posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    // 4. Calcular e exibir a média
    // Note que usamos (float) para garantir que a divisão não seja inteira
    float media = soma / n;
    printf("\n--- Resultados ---\n");
    printf("Soma total: %.2f\n", soma);
    printf("Media aritmetica: %.2f\n", media);

    // 5. Liberar a memória
    free(vetor);

    return 0;
}