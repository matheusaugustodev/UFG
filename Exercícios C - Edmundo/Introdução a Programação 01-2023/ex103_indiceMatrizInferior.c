#include <stdio.h>

int main() {

    int m, n, n1, m1;
    scanf("%d", &m);
    scanf("%d", &n);
  
    for(m1=2; m1<=m; m1++) {
        n1=1;
        printf("(%d,%d)", m1, n1);
        for(n1=2; n1<=n; n1++) {
            if(n1<m1) {
                printf("-(%d,%d)", m1, n1);
            }
        }
        printf("\n");
    }

    
    return 0;
}
