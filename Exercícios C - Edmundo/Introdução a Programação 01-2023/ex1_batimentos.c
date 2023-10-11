#include <stdio.h>

int main()
{
    int idade;
    float resultado;
    scanf("%d", &idade);
    resultado = (idade*365.25*24*60*60);
    printf("O CORACAO BATEU %.2f VEZES\n", resultado);

    return 0;
}
