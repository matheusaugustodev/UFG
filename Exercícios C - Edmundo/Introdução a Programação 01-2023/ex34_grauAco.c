#include <stdio.h>

int main() {
    
    
    int CC, DR, RT, grau;
    scanf("%i %i %i", &CC, &DR, &RT);
    if (CC<7 && DR>50 && RT>80000) {
        grau = 10;
    } else if(CC<7 && DR>50 && RT<=80000) {
        grau = 9;
    } else if(CC<7 && DR<50 && RT<=80000) {
        grau =8;
    } else {
        grau = 7;
    }
  
    printf("ACO DE GRAU = %i\n", grau);
  
    return 0;
}