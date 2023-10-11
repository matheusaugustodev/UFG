#include <stdio.h>

int main()
{
    
    int x, y, z, i, j, k;
    scanf("%d %d %d", &x, &y, &z);
    
    if(x>=y && x>=z) {
       k = x; 
    } else if(y>=x && y>=z) {
        k = y;
    } else {
        k = z;
    }
    j=1;
    i=2;
    
    do {
        if(x%i==0 || y%i==0 || z%i==0) {
            j=j*i;
            printf("%d %d %d :%d\n", x, y, z, i);

            if(x%i==0) {
                x=x/i;
            }
            if(y%i==0) {
                y=y/i;
            }
            if(z%i==0) {
                z=z/i;
            }
        }
        if(x%i!=0 && y%i!=0 && z%i!=0) {
            i++;
        }
    } while(i<=k);
    
    printf("MMC: %d\n", j);


    return 0;
}
