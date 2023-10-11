#include <stdio.h>

int main() {

    int n, i, j;
    j=0;
    scanf("%d", &n);

    for(i=2; i<=n; i++) {
        if(n%i==0) {
            j++;
        }
    }
    
    if(j>1 || n<2) {
        printf("NAO PRIMO\n");
    } else {
        printf("PRIMO\n");
    }
    


    return 0;
}
