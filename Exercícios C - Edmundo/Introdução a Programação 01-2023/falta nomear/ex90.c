#include <stdio.h>

int main() {
    
    int a, b;
    int contador = 0;
    scanf("%d %d", &a, &b);

    while (a<=b){
        a = a*1.03;
        b = b*1.015;
        contador++;
    }
    printf("ANOS = %d\n", contador);
    
    

    return 0;
}
