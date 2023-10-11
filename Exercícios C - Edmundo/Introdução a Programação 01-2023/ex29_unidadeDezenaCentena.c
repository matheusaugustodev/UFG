#include <stdio.h>

int main() {
    int numero, unidadeMilhar, centena, dezena, unidade;

    scanf("%d", &numero);
    
    // Calcula as unidades de milhar, centenas, dezenas e unidades do numero
    unidadeMilhar = numero / 1000;
    centena = (numero % 1000) / 100;
    dezena = (numero % 100) / 10;
    unidade = numero % 10;
    
    printf("(%s ordem) %d = ", unidadeMilhar > 0 ? "quarta" : (centena > 0 ? "terceira" : (dezena > 0 ? "segunda" : "primeira")), numero);
    
    if (unidadeMilhar > 0) {
        printf("%d unidade de milhar", unidadeMilhar);
    }
    
    if (centena > 0) {
        if (unidadeMilhar > 0) {
            printf(" + ");
        }
        printf("%d centena%s", centena, centena > 1 ? "s" : "");
    }
    
    if (dezena > 0) {
        if (unidadeMilhar > 0 || centena > 0) {
            printf(" + ");
        }
        printf("%d dezena%s", dezena, dezena > 1 ? "s" : "");
    }
    
    if (unidade > 0) {
        if (unidadeMilhar > 0 || centena > 0 || dezena > 0) {
            printf(" + ");
        }
        printf("%d unidade%s", unidade, unidade > 1 ? "s" : "");
    }
    
    printf(" = ");
    
    if (unidadeMilhar > 0) {
        printf("%d000", unidadeMilhar);
    }
    
    if (centena > 0) {
        if (unidadeMilhar > 0) {
            printf(" + ");
        }
        printf("%d00", centena);
    }
    
    if (dezena > 0) {
        if (unidadeMilhar > 0 || centena > 0) {
            printf(" + ");
        }
        printf("%d0", dezena);
    }
    
    if (unidade > 0) {
        if (unidadeMilhar > 0 || centena > 0 || dezena > 0) {
            printf(" + ");
        }
        printf("%d", unidade);
    }
    
    printf("\n");
    
    return 0;
}
