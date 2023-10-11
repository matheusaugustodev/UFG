#include <stdio.h>

int main()
{
    float fahrenheit, polegada, celsius, milimetro;
    scanf("%f", &fahrenheit);
    scanf("%f", &polegada);
    celsius = (5*(fahrenheit - 32))/9;
    milimetro = polegada*25.4;
    printf("O VALOR EM CELSIUS = %.2f\n", celsius);
    printf("A QUANTIDADE DE CHUVA E = %.2f\n", milimetro);
    return 0;
}
