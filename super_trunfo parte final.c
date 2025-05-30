
#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[30];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

float calcular_densidade(unsigned long int pop, float area) {
    return area != 0 ? pop / area : 0;
}

float calcular_pib_per_capita(float pib, unsigned long int pop) {
    return pop != 0 ? pib / pop : 0;
}

float calcular_super_poder(Carta c) {
    return c.populacao + c.area + c.pib + c.pontos_turisticos +
           calcular_pib_per_capita(c.pib, c.populacao) +
           (c.densidade != 0 ? 1 / c.densidade : 0);
}

int main() {
    Carta c1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 2300000.00, 12};
    Carta c2 = {"RJ", "002", "Rio de Janeiro", 6700000, 1182.30, 1500000.00, 9};

    c1.densidade = calcular_densidade(c1.populacao, c1.area);
    c2.densidade = calcular_densidade(c2.populacao, c2.area);

    c1.pib_per_capita = calcular_pib_per_capita(c1.pib, c1.populacao);
    c2.pib_per_capita = calcular_pib_per_capita(c2.pib, c2.populacao);

    c1.super_poder = calcular_super_poder(c1);
    c2.super_poder = calcular_super_poder(c2);

    printf("Comparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade < c2.densidade);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder);

    return 0;
}
