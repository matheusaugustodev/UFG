#include <stdio.h>

int main()
{
    int vetor[10001], n, i, j, k, contador, maior;
    
    scanf("%d\n", &n);
    
    while (n!=0) {
        maior= -999;
        for(i=0;i<n;i++) {
            vetor[i] = 0;
        }
        for(i=0; i<n; i++) {
            scanf("%d\n", &vetor[i]);
        }
        for(i=0; i<n; i++) {
            if(vetor[i]>=maior) {
                maior=vetor[i];
            }
        }
        for(i=0; i<=maior; i++) {
            contador=0;
            for(j=0;j<n;j++) {
                if(i>=vetor[j]) {
                    contador = contador+1;
                }
            }
            printf("(%d) %d\n", i, contador);
        }  
        scanf("%d\n", &n);
    }
    return 0;
}