#include <stdio.h>

int main() {

    int n, i, teste;
    float x, y;
    
    n=-1;
    while(n!=0) {
        scanf("%d", &n);
        if(n==0) break;
        teste=0;
        scanf("%f", &x);
        for(i=1; i<n; i++) {
            scanf("%f", &y);
            if(x>y) teste++;
            x=y;
        }
        if(teste==0) printf("ORDENADA\n");
        else printf("DESORDENADA\n");
    }
    
    
    return 0;
}
