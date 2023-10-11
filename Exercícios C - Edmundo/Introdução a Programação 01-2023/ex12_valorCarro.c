#include <stdio.h>
#include <math.h>

int main() {
    float preco, precoFinal, custoFabrica, percentualDistribuidor, percentualImposto;
    scanf("%f %f %f", &preco, &percentualDistribuidor, &percentualImposto);
    
    precoFinal = preco + preco*(percentualDistribuidor/100)
    + preco*(percentualImposto/100);
    
    printf("O VALOR DO CARRO E = %.2f\n", precoFinal);

   return 0;
}
