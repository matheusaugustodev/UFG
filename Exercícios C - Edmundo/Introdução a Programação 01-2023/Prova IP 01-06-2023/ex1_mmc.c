#include <stdio.h>

int main()
{
    
    int i, j, k, x, y, z;

    scanf("%d %d %d", &x, &y, &z);
    
    if(x>y && x>z) {
        k = x;
    } else if(y>x && y>z) {
        k = y;
    } else {
        k = z;
    }
        
    i=2;
    j=1;
    
    do {
        if(x%i==0 || y%i==0 || z%i==0) {
            printf("%d %d %d :%d\n", x, y, z, i);
            if(x%i==0) {
                x = x/i;
            }
            if(y%i==0) {
                y = y/i;
            }
            if(z%i==0) {
                z = z/i;
            }
            j = j*i;
        } else {
            i++;
        }
        
    } while(i<=k);
    printf("MMC: %d\n", j);
    
    

    return 0;
}
