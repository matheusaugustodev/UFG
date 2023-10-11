#include <stdio.h>
#include <math.h>

int main() {
    
    int x, x1, x2, x3, x4, numero;
    scanf("%i", &x);
    x1 = x/100;
    x2 = (x%100)/10;
    x3 = x%10;
    x4 = (x1 + (x2*3) + (x3*5))%7;
    numero = (x1*1000)+(x2*100)+(x3*10)+x4;
    printf("O NOVO NUMERO E = %i\n", numero);
    
    
    return 0;
}
