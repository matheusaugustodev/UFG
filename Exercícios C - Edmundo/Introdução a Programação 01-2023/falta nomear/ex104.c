#include <stdio.h>

int main()
{
    int n, x, y, i, n1, n2;
    
    scanf("%d", &n);
    
    for(i=1; i<=n; i++) {
        scanf("%d %d", &x, &y);
        n1 = ((x%10)*100)+(((x%100)/10)*10)+(x/100);
        n2 = ((y%10)*100)+(((y%100)/10)*10)+(y/100);
        
        if(n1>n2) {
            printf("%d\n", n1);
        } else {
            printf("%d\n", n2);
        }
    }
    
    

    return 0;
}
