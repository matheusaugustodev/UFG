#include <stdio.h>

int main()
{
    
    
    int num, x1, x2, x3, x4, x5, x6, x7, x8, resultado;
    scanf("%i", &num);
    if(num<0 || num>255) {
        printf("Numero invalido!\n");
    } else {
        x1 = num%2;
        x2 = (num/2)%2;
        x3 = ((num/2)/2)%2;
        x4 = (((num/2)/2)/2)%2;
        x5 = ((((num/2)/2)/2))/2%2;
        x6 = (((((num/2)/2)/2))/2)/2%2;
        x7 = ((((((num/2)/2)/2))/2)/2)/2%2;
        x8 = (((((((num/2)/2)/2))/2)/2)/2)/2%2;
        resultado= (x8*10000000) +(x7*1000000)+(x6*100000)+(x5*10000)+(x4*1000)+(x3*100)+(x2*10)+x1;
        printf("%08i\n", resultado);
        
    }
    
    return 0;
}
