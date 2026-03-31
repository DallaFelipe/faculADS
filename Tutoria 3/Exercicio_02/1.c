#include <stdio.h>
#include <stdlib.h>

// 1. Definição da struct Produto
typedef struct {
    int id;
    float preco;
} Produto;

int main() {
    // 2. Declaração do ponteiro para a struct
    Produto *p;

    // 3. Alocação dinâmica de memória para um objeto Produto
    p = (Produto *) malloc(sizeof(Produto));

    // Verificação de segurança
    if (p == NULL) {
        printf("Erro ao alocar memoria para o produto.\n");
        return 1;
    }

    // 4. Atribuição de valores utilizando exclusivamente o operador seta (->)
    p->id = 101;
    p->preco = 250.50;

    // Exibição dos dados também usando a seta
    printf("--- Dados do Produto ---\n");
    printf("ID: %d\n", p->id);
    printf("Preco: R$ %.2f\n", p->preco);

    // 5. Liberação da memória
    free(p);

    return 0;
}

//p: É apenas um endereço de memória
//*p: É o objeto Produto inteiro localizado naquele endereço.
//p->id: Diz ao compilador: "Vá ao endereço p, veja onde começa o campo id 
//e altere o valor lá".