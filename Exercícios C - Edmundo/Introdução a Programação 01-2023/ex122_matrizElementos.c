#include <stdio.h>

int main()
{
    int i, j, k=0, linha, coluna, matriz[100];
    
    while(linha<1 || linha>10) scanf("%d", &linha);
    while(coluna<1 || coluna>10) scanf("%d", &coluna);
    
    for(i=0; i<linha*coluna; i++) scanf("%d", &matriz[i]);
    
    for(i=1; i<=linha; i++) {
        printf("linha %d: ", i);
        for(j=0; j<coluna; j++) {
            if(j==coluna-1) printf("%d\n", matriz[k]);
            else printf("%d,", matriz[k]);
            k++;
        }
    }
    

    return 0;
}
