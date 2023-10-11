#include <stdio.h>

int main()
{
    int x, y, i, j, k=1, p=1;
    
    scanf("%d %d", &y, &x);
    
    
    for(i=0; i<y; i++) {
        
        for(j=0; j<x; j++) {
            
            if(k==1) {
                if(j==0) printf("0");
                else printf(" 0");
            } else {
                if(j==0) printf("%d", p);
                else printf(" %d", p);
                p++;
            }
            
            
            k *= -1;
        }
        
        if(x%2 == 0) k *= -1;
        
        printf("\n");
    }

    return 0;
}
