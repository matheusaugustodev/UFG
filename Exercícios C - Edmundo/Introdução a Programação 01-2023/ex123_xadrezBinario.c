#include <stdio.h>

int main()
{
    int i, j, k=-1, linha, coluna;
    
    scanf("%d %d", &linha, &coluna);
    
    for(i=0; i<linha; i++) {
        for(j=0; j<coluna; j++) {
            k*=-1;
            if(k==1) printf("1");
            else printf("0");
        }
        k*=-1;
        printf("\n");
    }

    return 0;
}