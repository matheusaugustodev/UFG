#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta, raiz1, raiz2;
    scanf("%f %f %f", &a, &b, &c);
    delta = (b*b)-(4*a*c);
    raiz1 = (-b + sqrt(delta))/(2*a);
    raiz2 = (-b - sqrt(delta))/(2*a);
    if(delta<0){
        printf("RAIZES IMAGINARIAS\n");
    } else if(delta>0) {
        printf("RAIZES DISTINTAS\nX1 = %.2f\nX2 = %.2f\n", raiz1, raiz2);
    } else {
        // delta = 0
        printf("RAIZ UNICA\nX1 =  %.2f\n", raiz1);
    }
    
    
    return 0;
}
