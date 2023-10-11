#include <stdio.h>

int main()
{
    long int CC, DR, RT, grau;
    
    scanf("%ld", &CC);
    scanf("%ld", &DR);
    scanf("%ld", &RT);
    
    if(CC < 7) {
        if(DR > 50) {
            if(RT > 80000) grau = 10;
            else grau = 9;
        } else 
            grau = 8;
    } else {
        grau = 7;
    }
    
    printf("ACO DE GRAU = %ld\n", grau);
}