#include <stdio.h>

int main()
{
    int n, i, j;
    int vetor[1000];
    
    scanf("%d", &n);
    
    for(i=0; i<n*n; i++) {
        scanf("%d", &vetor[i]);
    }
    
    j=0;
    for(i=0; i<n*n; i++) {
        if(i==j) {
            printf("%d\n", vetor[i]);
            j += n+1;
        }
    }
    
    return 0;
}