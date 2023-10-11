#include <stdio.h>

int main()
{
    int vetor[5000], n, i, soma;

    
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
        soma = soma + vetor[i];
    }

    printf("%d\n", soma);   

    
    
    return 0;
}