#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Definição da struct Endereco
typedef struct {
    char rua[50];
    int numero;
} Endereco;

// 2. Definição da struct Pessoa com ponteiro para Endereco
typedef struct {
    char nome[50];
    Endereco *end; // Ponteiro para outra struct no Heap
} Pessoa;

int main() {
    // 3. Alocar a Pessoa no Heap
    Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
    
    if (p == NULL) return 1;

    // 4. Alocar o Endereco no Heap separadamente
    p->end = (Endereco *) malloc(sizeof(Endereco));

    if (p->end == NULL) {
        free(p); // Se falhar aqui, precisamos liberar a pessoa alocada antes
        return 1;
    }

    // 5. Atribuir valores e conectar os dados
    strcpy(p->nome, "Carlos Silva");
    strcpy(p->end->rua, "Avenida Central");
    p->end->numero = 100;

    // 6. Exibir os dados (usando a seta dupla para chegar no endereço)
    printf("Nome: %s\n", p->nome);
    printf("Endereco: %s, Numero: %d\n", p->end->rua, p->end->numero);

    // 7. Liberação da memória (IMPORTANTE: Ordem inversa)
    // Primeiro liberamos o que está apontado (Endereco)
    free(p->end);
    // Depois liberamos a estrutura principal (Pessoa)
    free(p);

    return 0;
}

