#include <stdio.h>

int main()
{
    int vetor[5000], n, i;
    
    scanf("%d\n", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
    }

    for(i=0; i<n; i++) {
        if(i==n) {
            printf("%d\n", vetor[i]);  
        } else {
            printf("%d ", vetor[i]);
        }
    }
    
    return 0;
}