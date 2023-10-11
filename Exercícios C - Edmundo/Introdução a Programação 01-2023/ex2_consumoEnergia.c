#include <stdio.h>

int main()
{
    
    float salario, consumo, valorKw, precoTotal, precoDesconto;
    scanf("%f %f", &salario, &consumo);
    valorKw = (0.7 * salario)/100;
    precoTotal = valorKw*consumo;
    precoDesconto = precoTotal*0.9;
    printf("Custo por kW: R$ %.2f\n", valorKw);
    printf("Custo do consumo: R$ %.2f\n", precoTotal);
    printf("Custo com desconto: R$ %.2f\n", precoDesconto);

    return 0;
}
