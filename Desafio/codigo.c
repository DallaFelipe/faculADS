#include <stdio.h>
#include <string.h>


double calcularMedia(double n1, double n2, double n3) {
    return (n1 + n2 + n3) / 3.0;
}

int main() {
    
    char nome[20];
    int idade;
    double nota1, nota2, nota3, media;
    int numeros[5]; 
    int soma = 0;
    int maior;

    printf("Digite seu nome: ");
    scanf("%s", nome);

    do {
        printf("Digite sua idade: ");
        scanf("%d", &idade);
        if (idade < 0) {
            printf("Erro: A idade nao pode ser negativa.\n");
        }
    } while (idade < 0);

    printf("Digite a nota 1: ");
    scanf("%f", &nota1);
    printf("Digite a nota 2: ");
    scanf("%f", &nota2);
    printf("Digite a nota 3: ");
    scanf("%f", &nota3);

    media = calcularMedia(nota1, nota2, nota3);
    printf("\nMedia final: %.2f\n", media);

    if (media >= 7.0) {
        printf("Situacao: Aprovado\n");
    } else if (media >= 5.0) {
        printf("Situacao: Recuperacao\n");
    } else {
        printf("Situacao: Reprovado\n");
    }

    printf("\n--- Desafio dos Numeros ---\n");


    for (int i = 0; i < 5; i++) {
        printf("Digite o %do numero inteiro: ", i + 1);
        scanf("%d", &numeros[i]);

      
        soma += numeros[i];

       
        if (i == 0) {
            maior = numeros[i];
        } else {
            if (numeros[i] > maior) {
                maior = numeros[i];
            }
        }
    }

  
    printf("\nA soma dos numeros e: %d", soma);
    printf("\nO maior numero digitado e: %d\n", maior);

    return 0;
}