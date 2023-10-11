#include <stdio.h>

int main() {
    float raio, altura, area_circulo, area_lateral, area_total, custo;
    float PRECO_ALUMINIO, PI;
    PRECO_ALUMINIO = 100.00;
    PI = 3.14159;

    scanf("%f", &raio);
    scanf("%f", &altura);

    area_circulo = PI * raio * raio;
    area_lateral = 2 * PI * raio * altura;
    area_total = 2 * area_circulo + area_lateral;

    custo = area_total * PRECO_ALUMINIO;

    printf("O VALOR DO CUSTO E = %.2f\n", custo);

    return 0;
}
