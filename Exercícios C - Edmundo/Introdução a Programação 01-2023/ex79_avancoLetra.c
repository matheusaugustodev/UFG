#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, n, total=0;
    char x[1000], y[1000];
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%s %s", x, y);
        
        for(j=0; j < strlen(x); j++) {

            if(x[j] < y[j]) total+=y[j] - x[j];

            if(x[j] > y[j]) total+= 26 - x[j] + y[j];
        }
        printf("%d\n", total);  
        total=0;
    }
    
    return 0;
}