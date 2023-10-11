#include <stdio.h>

int main()
{
    
    int n, i, j;
    scanf("%d", &n);
    
    for(i=1; i<n; i++) {
        
        for(j=1; j<=n; j++) {
            
            if(j>i && j<n) {
                printf("(%d,%d) - ", i, j);
            }
            if(j>i && j==n) {
                printf("(%d,%d)\n", i, j);
            }
        }
    }
    


    return 0;
}