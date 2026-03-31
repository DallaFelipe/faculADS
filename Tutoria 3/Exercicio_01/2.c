#include <stdio.h>
#include <stdlib.h>

int main() {
    // Definindo o tamanho de 1GB em bytes
    // Usamos 'unsigned long' para evitar estouro de capacidade em sistemas 32-bits
    size_t giga_byte = 1024ULL * 1024 * 1024;

    // Tentativa de alocação
    printf("Tentando alocar 1GB de memoria...\n");
    char *buffer = (char *) malloc(giga_byte);

    // Verificação de segurança (NULL check)
    if (buffer == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar 1GB de memoria. Memoria insuficiente.\n");
        return 1;
    }

    // Sucesso
    printf("Sucesso! 1GB de memoria alocado no endereco: %p\n", (void*)buffer);

    // Liberação imediata
    free(buffer);
    printf("Memoria liberada com sucesso.\n");

    return 0;
}

//O tipo size_t é o tipo adequado para representar tamanhos de objetos em C. 
//O sufixo ULL (Unsigned Long Long) garante que o cálculo da multiplicação
// não sofra uma "Sobrecarga"

//O uso de fprintf(stderr, ...) é uma prática recomendada para exibir
// mensagens de erro, separando a saída de erro da saída padrão do programa.
