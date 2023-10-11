#include <stdio.h>

int main()
{
    int n, tr=0, i, j, matriz[1000][1000], transposta[1000][1000], resultado[1000][1000];
    
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &matriz[i][j]);
            if(i==j) tr += matriz[i][j];
        }
    }
    
    for(j=0; j<n; j++) {
        for(i=0; i<n; i++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            resultado[i][j] = matriz[i][j]*tr;
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            resultado[i][j] += transposta[i][j];  
        }
    }
        
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if (j == 0) printf("%d", resultado[i][j]);
            else printf(" %d", resultado[i][j]);
        }
        printf("\n");
    }
        
    
    return 0;
}
