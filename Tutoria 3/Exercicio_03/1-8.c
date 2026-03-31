#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Estruturas ---
typedef struct {
    char rua[50];
    int numero;
} Endereco;

typedef struct {
    int id;
    float nota;
    char *nome;     // Alocação dinâmica de string
    Endereco *end;  // Ponteiro para outra struct
} Aluno;

// --- Funções Auxiliares ---

// Liberação Profunda de Matriz
void liberar_matriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Clonagem de Objeto (Deep Copy)
Aluno* clonar_aluno(Aluno *origem) {
    if (origem == NULL) return NULL;
    Aluno *novo = (Aluno *) malloc(sizeof(Aluno));
    *novo = *origem; // Copia ID e Nota
    
    // Aloca novo espaço para o nome e copia
    novo->nome = (char *) malloc((strlen(origem->nome) + 1) * sizeof(char));
    strcpy(novo->nome, origem->nome);
    
    // Aloca novo espaço para o endereço e copia
    novo->end = (Endereco *) malloc(sizeof(Endereco));
    *(novo->end) = *(origem->end);
    
    return novo;
}

// Busca Sequencial (Retorna endereço ou NULL)
Aluno* buscar_aluno(Aluno *turma, int tam, int id_busca) {
    for (int i = 0; i < tam; i++) {
        if (turma[i].id == id_busca) return &turma[i];
    }
    return NULL;
}

int main() {
    // 1. REDIMENSIONAMENTO (realloc)
    int *v = (int *) malloc(2 * sizeof(int));
    v[0] = 10; v[1] = 20;
    v = (int *) realloc(v, 4 * sizeof(int)); // Expandindo
    v[2] = 30; v[3] = 40;
    printf("Vetor realocado (pos 3): %d\n", v[3]);
    free(v);

    // 2. MATRIZ DINÂMICA (M x N)
    int M = 3, N = 3;
    int **matriz = (int **) malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        matriz[i] = (int *) malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            matriz[i][j] = i + j; // O(n^2) para preencher
        }
    }
    // Liberação Profunda
    liberar_matriz(matriz, M);

    // 3. VETOR DE STRINGS (Cidades)
    char **cidades = (char **) malloc(2 * sizeof(char *));
    cidades[0] = strdup("Florianopolis"); // strdup faz o malloc e strcpy internamente
    cidades[1] = strdup("Jaragua do Sul");
    printf("Cidade 2: %s\n", cidades[1]);
    free(cidades[0]); free(cidades[1]); free(cidades);

    // 4. ESTRUTURAS COMPLEXAS E FILTRAGEM
    int qtd = 3;
    Aluno *turma = (Aluno *) malloc(qtd * sizeof(Aluno));
    
    // Exemplo de preenchimento de 1 aluno com alocação em níveis
    turma[0].id = 1;
    turma[0].nota = 8.5;
    turma[0].nome = strdup("Alice");
    turma[0].end = (Endereco *) malloc(sizeof(Endereco));
    strcpy(turma[0].end->rua, "Rua das Flores");
    
    turma[1].id = 2; turma[1].nota = 5.0; turma[1].nome = strdup("Bob");
    turma[1].end = (Endereco *) malloc(sizeof(Endereco));
    
    turma[2].id = 3; turma[2].nota = 9.0; turma[2].nome = strdup("Clara");
    turma[2].end = (Endereco *) malloc(sizeof(Endereco));

    // Busca
    Aluno *encontrado = buscar_aluno(turma, qtd, 3);
    if (encontrado) printf("Busca: %s nota %.1f\n", encontrado->nome, encontrado->nota);

// Filtragem (Apenas aprovados > 7.0)
    int aprovados_count = 0;
    Aluno **aprovados = (Aluno **) malloc(qtd * sizeof(Aluno *));
    for (int i = 0; i < qtd; i++) {
        if (turma[i].nota > 7.0) {
            aprovados[aprovados_count++] = &turma[i];
        }
    }

    printf("Aprovados encontrados: %d\n", aprovados_count);

    // Clonagem
    Aluno *clone = clonar_aluno(&turma[0]);
    printf("Clone de %s criado com sucesso.\n", clone->nome);

    // --- LIBERAÇÃO TOTAL ---
    for (int i = 0; i < qtd; i++) {
        free(turma[i].nome);
        free(turma[i].end);
    }
    free(turma);
    free(aprovados);
    free(clone->nome);
    free(clone->end);
    free(clone);

    return 0;
}

// O realloc gerencia o movimento de dados se o bloco original não puder crescer.

//Para a struct Aluno, tem que seguir a regra: aloque o recipiente -> aloque os campos internos.
//Para liberar: limpe os campos internos -> libere o recipiente.

// No preenchimento da matriz, cada i percorre todos os j, resultando em N X N operações.

//O uso de strdup (ou malloc+strcpy) garante que cada string tenha seu próprio endereço,
//evitando que múltiplos ponteiros apontem para um buffer temporário que será sobrescrito.