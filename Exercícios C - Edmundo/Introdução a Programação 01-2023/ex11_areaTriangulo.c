#include <stdio.h>
#include <math.h>

int main() {
    float T, area, A, B, C;
    scanf("%f %f %f", &A, &B, &C);
    T = (A+B+C)/2;
    area = sqrt(T*(T - A)*(T - B)* (T - C));
    printf("A AREA DO TRIANGULO E = %.2f\n", area);

   return 0;
}
