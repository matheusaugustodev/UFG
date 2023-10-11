#include <stdio.h>

unsigned long int fat( unsigned int n) {
    unsigned long int valor = 1, i;
    
    for(i=1; i<=n; i++) valor *= i;
    return valor;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d! = %ld\n", n, fat(n));

    return 0;
}

