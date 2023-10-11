#include <stdio.h>
#include <math.h>

int main() {
    
    float valor, resultado;
    int n;
    scanf("%f", &valor);
    n = valor*10 + 0.5;
    resultado = (float)n/10;
    printf("%.6f\n", resultado);
    
    n = valor*100 + 0.5;
    resultado = (float)n/100;
    printf("%.6f\n", resultado);
    
    n = valor*1000 + 0.5;
    resultado = (float)n/1000;
    printf("%.6f\n", resultado);
    
    return 0;
}
