#include <stdio.h>

int main()
{
    float a, b, c, d, determinante;
    
    scanf("%f %f", &a, &b);
    scanf("%f %f", &c, &d);
    determinante = a*d - b*c;
    printf("%.2f", determinante);
    
    return 0;
}