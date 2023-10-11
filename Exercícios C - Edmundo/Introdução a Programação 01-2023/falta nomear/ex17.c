#include <stdio.h>

int main()
{
    
    int num, x1, x2, x3, resultado; 
    scanf("%i", &num);
    x1 = num/100;
    x2 = (num%100)/10;
    x3 = num%10;
    resultado = (x3*100) + (x2*10) + x1;
    printf("%i\n", resultado);

    return 0;
}
