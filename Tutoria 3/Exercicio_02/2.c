#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Definição da struct Aluno
typedef struct {
    char nome[50];
    float nota;
} Aluno;

int main() {
    // 2. Declaração do ponteiro para o array de alunos
    Aluno *turma;
    int i;

    // 3. Alocação dinâmica para 3 estruturas do tipo Aluno
    turma = (Aluno *) malloc(3 * sizeof(Aluno));

    // Verificação de segurança
    if (turma == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return 1;
    }

    // 4. Preenchimento do array dinâmico
    for (i = 0; i < 3; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        // Usamos fgets para permitir nomes com espaços
        scanf(" %[^\n]s", turma[i].nome); 
        
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &turma[i].nota);
        printf("\n");
    }

    // 5. Exibição dos dados armazenados
    printf("--- Lista de Alunos ---\n");
    for (i = 0; i < 3; i++) {
        // Como 'turma' é tratado como array, usamos o ponto '.' 
        // para acessar os membros de cada elemento turma[i]
        printf("Aluno: %-15s | Nota: %.1f\n", turma[i].nome, turma[i].nota);
    }

    // 6. Liberação da memória
    free(turma);

    return 0;
}