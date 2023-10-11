#include <stdio.h>

int main() {
    
    int n, n1;
    int i;
    scanf("%d", &n);
    n1 = n;
    i = 1;
    for(i=1; i<n1; i++) {
        n = n*(n1-i);
    }
    printf("%d!  = %d\n", n1, n);
    
    

    return 0;
}
