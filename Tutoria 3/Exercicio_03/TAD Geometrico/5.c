#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Necessário para a função sqrt()
#include "ponto.h"

// Definição da estrutura real (oculta para o usuário do TAD)
struct ponto {
    float x;
    float y;
};

// Função para criar e alocar o ponto dinamicamente
Ponto* ponto_criar(float x, float y) {
    Ponto* p = (Ponto*) malloc(sizeof(struct ponto));
    
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    
    return p;
}

// Função para calcular a distância: d = sqrt((x2-x1)^2 + (y2-y1)^2)
float ponto_distancia(Ponto* p1, Ponto* p2) {
    if (p1 == NULL || p2 == NULL) return -1.0; // Verificação de erro

    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    
    return sqrt(dx * dx + dy * dy);
}

// Função para destruir e liberar a memória
void ponto_destruir(Ponto* p) {
    if (p != NULL) {
        free(p);
    }
}