#include <stdio.h>
#include <math.h>

int main() {
    
    float a, b, c, p;
    scanf("%f %f %f", &a, &b, &c);

    if(
        ((fabs(b-c) < a)&& a < (b+c)) &&
        ((fabs(a-c) < b)&& b < (a+c)) &&
        ((fabs(a-b) < c)&& c < (a+b))
    ) {
        p = (a + b + c);
        printf("Perimetro = %.1f\n", p);
    } else {
        p = (((a + b)*c)/2);
        printf("Area = %.1f\n", p);
    }

    return 0;
}
