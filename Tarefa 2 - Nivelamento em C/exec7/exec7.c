#include <stdio.h>

int main() {
    float n1, n2, n3, media;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);

    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    printf("Digite o terceiro numero: ");
    scanf("%f", &n3);


    media = (n1 + n2 + n3) / 3;

    printf("\nA media final e: %.2f\n", media);

    if (media >= 6.0) {
        printf("Resultado: Aprovado \n");
    } else {
        printf("Resultado: Reprovado \n");
    }

    return 0;
}