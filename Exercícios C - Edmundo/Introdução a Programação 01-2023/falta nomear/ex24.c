#include <stdio.h>

int main()
{
    int hora;
    float preco;
    scanf("%i", &hora);
    preco = ((hora/3)*10)+(5*(hora%3));
    printf("O VALOR A PAGAR E = %.2f\n", preco);
    
    
    return 0;
}
