#include <stdio.h>

int main()
{
    int vetor[5000], n, i;
    
    scanf("%d\n", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
    }

    for(i=n-1; i>=0; i--) {
        if(i==0) {
            printf("%d\n", vetor[i]);  
        } else {
            printf("%d ", vetor[i]);
        }
    }
    
    return 0;
}