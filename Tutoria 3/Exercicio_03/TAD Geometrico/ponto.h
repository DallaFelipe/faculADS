#ifndef PONTO_H
#define PONTO_H

/* * Declaração da estrutura opaca. 
 * O usuário do TAD sabe que existe um 'Ponto', mas não sabe 
 * se ele contém int, float, ou quais são os nomes dos campos.
 */
typedef struct ponto Ponto;

/* * Cria um novo ponto dinamicamente.
 * Retorna um ponteiro para a estrutura alocada.
 */
Ponto* ponto_criar(float x, float y);

/* * Calcula a distância euclidiana entre dois pontos.
 */
float ponto_distancia(Ponto* p1, Ponto* p2);

/* * Libera a memória alocada para o ponto.
 */
void ponto_destruir(Ponto* p);

#endif // PONTO_H

//QUando se utiliza sua biblioteca não é possivel modificar os campos x 
//ou y diretamente (ex: p->x = 10 causaria erro de compilação).
// É obrigatorio usar as funções utilizadas.

//Você pode mudar a implementação interna (por exemplo, 
//mudar de coordenadas cartesianas para polares)sem que 
//o usuário precise alterar uma única linha de código no programa principal.