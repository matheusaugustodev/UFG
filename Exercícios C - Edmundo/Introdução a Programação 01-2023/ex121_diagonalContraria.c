#include <stdio.h>

int main()
{
    int n, i, j, k, m;
    int vetor[1000];
    
    scanf("%d", &n);
    
    for(i=0; i<n*n; i++) {
        scanf("%d", &vetor[i]);
    }
    
    j=n-1;
    k=2;
    m=1;
    for(i=0; i<n*n; i++) {
        if(i==j) {
            if(i!=(n*n)-1) {
                printf("%d\n", vetor[i]);
                j = n*k-m-1;
                k++;
                m++;
            }
        }
    }
    
    return 0;
}