#include <stdio.h>

int main()
{
    float salario, reajuste;
    scanf("%f", &salario);
    
    if (salario < 300) {
        reajuste = salario*1.5;
    } else {
        reajuste = salario*1.3;
    }
    
    printf("SALARIO COM REAJUSTE = %.2f\n", reajuste);
    
    
    return 0;
}
