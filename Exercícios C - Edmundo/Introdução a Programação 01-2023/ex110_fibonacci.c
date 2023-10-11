#include <stdio.h>

int main()
{
    
    int n, x, x1, x2, f1, f2, i, j;
    scanf("%d %d %d", &n, &f1, &f2);
    
    scanf("%d", &x);
    scanf("%d", &x1);   
    printf("OK\n");
    printf("OK\n");    
    
    for(i=1; i<=(n-2); i++) {
        scanf("%d", &x2);

        if(f1+f2==x2) {
            printf("OK\n"); 
            f1=f2;
            f2=x2;
            if(i==(n-2)) {
                printf("A serie informada e de Fibonacci\n");
            }
        } else {
            printf("Nao e Fibonacci\n");
            i=n-2;
        }
    }

    return 0;
}
