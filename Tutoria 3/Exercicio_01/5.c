#include <stdio.h>

// Função que recebe o endereço (ponteiro) de um inteiro
void dobrarValor(int *ptr) {
    // Utilizamos o operador de indireção (*) para acessar e 
    // modificar o valor no endereço recebido
    *ptr = (*ptr) * 2;
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("Valor original: %d\n", numero);

    // Chamamos a função passando o endereço da variável 'numero' usando '&'
    dobrarValor(&numero);

    printf("Valor apos a funcao (dobrado): %d\n", numero);

    return 0;
}

//Diferente da passagem por valor (onde a função recebe apenas uma cópia),
//ao passar o endereço, a função dobrarValor ganha permissão para manipular
//diretamente a gaveta de memória que pertence ao main.

//void dobrarValor(int *ptr): O asterisco indica que a função espera receber
//um ponteiro, não um número comum.

//Operador & no main: Usamos &numero para extrair o endereço de onde o valor 
//está guardado.

//Operador * dentro da função: Quando fazemos *ptr, estamos dizendo ao computador:
//"Vá até o endereço guardado em ptr e altere o que estiver lá".