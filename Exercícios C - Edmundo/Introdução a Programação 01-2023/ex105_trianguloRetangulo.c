#include <stdio.h>

int main()
{
    
    int n, i, j, k;
    scanf("%d", &n);
    for(k=1; k<=n; k++) {
        
        for(i=1; i<=n; i++) {
            
            for(j=1; j<=n; j++) {
                
                if((i*i+j*j)<=n*n){
                    if(k*k == (i*i+j*j) && i<=j) {
                        printf("hipotenusa = %d, catetos %d e %d\n",k, i, j);
                    }
                }
            }
        }
        
        
    }

    return 0;
}
