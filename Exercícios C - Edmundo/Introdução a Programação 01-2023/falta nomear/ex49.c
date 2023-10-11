#include <stdio.h>

int main()
{
    int vetor[100], n, i, j;
    
    while(scanf("%d",&n)!=EOF) {
        if(n!=EOF) {
            i=0;
            do {
                vetor[i] = n%2;
                n = n/2;
                i++;
            } while(n>0);
            for(j=i-1; j>=0; j--) {
                if(j==0) {
                    printf("%d", vetor[j]);
                } else {
                    printf("%d ", vetor[j]);
                }
            } 
            printf("\n");
        }
    }
    return 0;
}