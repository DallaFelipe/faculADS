#include <stdio.h>
#include <stdlib.h>

// Definição da struct Produto
typedef struct {
    int id;
    float preco;
} Produto;

// Função que zera os campos da struct via ponteiro
void reset_estoque(Produto *p) {
    if (p != NULL) {
        p->id = 0;      // Zera o ID
        p->preco = 0.0; // Zera o Preço
    }
}

int main() {
    // 1. Alocando um produto dinamicamente
    Produto *meu_produto = (Produto *) malloc(sizeof(Produto));

    if (meu_produto == NULL) return 1;

    // 2. Atribuindo valores iniciais
    meu_produto->id = 505;
    meu_produto->preco = 99.90;

    printf("Antes do reset: ID %d, Preco R$ %.2f\n", meu_produto->id, meu_produto->preco);

    // 3. Chamando a função de reset
    // Passamos o ponteiro 'meu_produto' diretamente
    reset_estoque(meu_produto);

    printf("Depois do reset: ID %d, Preco R$ %.2f\n", meu_produto->id, meu_produto->preco);

    // 4. Liberando a memória
    free(meu_produto);

    return 0;
}

//Quando é passado Produto *p para a função, não está sendo enviado uma 
//cópia dos dados, mas sim o endereço de onde os dados moram.

// Sempre é bom adicionar um check if (p != NULL) dentro da função.
//é uma excelente prática defensiva para evitar que o programa tente acessar um
//endereço inválido e cause um erro de segmentação (Segmentation Fault).

//Essa função é extremamente útil em sistemas reais para "limpar" objetos antes de 
//reutilizá-los ou antes de deletá-los, garantindo que não fiquem "lixos de memória" 
//(valores antigos) residuais.

//Se tivesse sido declarado o produto de forma estática(ex: Produto prod;)
//a função seria chamada usando o operador de endereço: reset_estoque(&prod);.