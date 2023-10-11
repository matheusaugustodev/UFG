#include <stdio.h>

int main()
{
    
    int n, i, j;
    scanf("%d", &n);
    j=1;
    
    for(i=1; i<n; i++) {
        if(i==1) {
            printf("%d = %d", n, i);
        } else {
            if(n%i==0) {
                j = j+i;
                printf(" + %d", i);
            }
        }
    }
    if(j==i) {
        printf(" = %d (NUMERO PERFEITO)\n", j);
    } else {
        printf(" = %d (NUMERO NAO E PERFEITO)\n", j);        
    }
    return 0;
}
