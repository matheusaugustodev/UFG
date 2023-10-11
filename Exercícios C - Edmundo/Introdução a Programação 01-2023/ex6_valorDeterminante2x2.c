#include <stdio.h>

int main() {
    float a, b, c, d, x;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    x = a*d- b*c;
    printf("O VALOR DO DETERMINANTE E = %.2f\n", x);
    
    return 0;
}
