#include <stdio.h>
int main() {
    float valorUser;

    printf("Digite um número real: ");
    scanf("%f", &valorUser  );

    printf("O valor formatado é: %.2f\n", valorUser);

    return 0;
}