#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int idade;
} Usuario;

int main() {
    // 1. Criar um buffer temporário para ler o nome do teclado
    char buffer[100];
    Usuario *user;

    // 2. Alocar a struct Usuario dinamicamente
    user = (Usuario *) malloc(sizeof(Usuario));
    if (user == NULL) return 1;

    printf("Digite o nome do usuario: ");
    scanf(" %[^\n]s", buffer); // Lê a linha incluindo espaços

    // 3. Alocar o espaço EXATO para o nome dentro da struct
    // strlen(buffer) nos dá a quantidade de letras
    // +1 é para o caractere nulo '\0' que encerra a string
    user->nome = (char *) malloc((strlen(buffer) + 1) * sizeof(char));

    if (user->nome == NULL) {
        free(user);
        return 1;
    }

    // 4. Copiar o conteúdo do buffer para a memória alocada
    strcpy(user->nome, buffer);

    printf("\n--- Usuario Cadastrado ---\n");
    printf("Nome: %s\n", user->nome);
    printf("Tamanho da alocacao do nome: %zu bytes\n", strlen(user->nome) + 1);

    // 5. LIBERAÇÃO DA MEMÓRIA (Ordem inversa da alocação)
    // Primeiro liberamos o que está "dentro", depois o "recipiente"
    free(user->nome);
    free(user);

    return 0;
}

//strings em C precisam de um caractere extra para o terminador nulo (\0)
//por isso precisa alocar strlen(buffer) + 1.

//Como não da pra saber o tamanho do nome antes do usuário digitar
//tem que usar um char buffer[100] como área de espera.

//strlen(buffer) + 1: Este é um detalhe  importante. Sem o +1, a função printf ou strcpy
//vai ler um espaço de memória que não pertence ao programa, 
//o que pode causar erros.