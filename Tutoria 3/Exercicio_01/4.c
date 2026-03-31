#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *ptr;
    int *inicio; // Ponteiro auxiliar para não perdermos a referência do início

    // 1. Alocar um vetor de 5 posições
    ptr = (int *) malloc(5 * sizeof(int));

    if (ptr == NULL) {
        printf("Erro de alocacao.\n");
        return 1;
    }

    // Guardamos o endereço inicial para podermos liberar a memória depois
    inicio = ptr;

    // 2. Preencher o vetor usando aritmética de ponteiros
    for (i = 0; i < 5; i++) {
        printf("Digite o valor para a posicao %d: ", i);
        scanf("%d", ptr); // Passamos o endereço atual do ponteiro
        ptr++;            // Move o ponteiro para a próxima posição de memória
    }

    // 3. Resetar o ponteiro para o início para a impressão
    ptr = inicio;

    printf("\nValores no vetor (acessados via *ptr++):\n");

    // 4. Percorrer e imprimir usando apenas indireção e incremento
    for (i = 0; i < 5; i++) {
        // O asterisco (*) acessa o conteúdo, e o ++ move para o próximo endereço
        printf("Endereco: %p | Valor: %d\n", (void*)ptr, *ptr);
        ptr++; 
    }

    // 5. Liberar a memória usando o ponteiro original (inicio)
    free(inicio);

    return 0;
}

//Se for incrementado o ponteiro ptr e não salvar o endereço inicial (como feito com a variável inicio), 
//não dá para usar o free() corretamente depois, pois a função free 
//exige o endereço exato que foi retornado pelo malloc.