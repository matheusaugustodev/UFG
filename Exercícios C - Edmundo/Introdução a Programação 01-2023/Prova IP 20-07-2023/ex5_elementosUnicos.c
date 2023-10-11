#include <stdio.h>

int main()
{
    int n, i, j, temp, vetor[1000], novoVetor[1000];
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
        scanf("%d", &vetor[i]);
    
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(vetor[i] > vetor[j]) {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
    
    j = 0;
    novoVetor[j] = vetor[0];
    for(i=1; i<n; i++) {
        if(vetor[i] != vetor[i-1]) {
            j++;
            novoVetor[j] = vetor[i];
        }
    }
    
    for(i=0; i<=j; i++)
        printf("%d\n", novoVetor[i]);
    
    return 0;
}
