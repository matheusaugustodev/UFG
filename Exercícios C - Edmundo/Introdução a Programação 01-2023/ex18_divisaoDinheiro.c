#include <stdio.h>

int main()
{
    
    int num, cem, cinquenta, dez, um;
    scanf("%i", &num);
    cem = num/100;
    cinquenta = (num%cem)/50;
    dez = (num%50)/10;
    um = (num%10);
    printf("NOTAS DE 100 = %i\n", cem);
    printf("NOTAS DE 50 = %i\n", cinquenta);
    printf("NOTAS DE 10 = %i\n", dez);
    printf("MOEDAS DE 1 = %i\n", um);
    

    return 0;
}
