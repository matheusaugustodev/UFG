#include <stdio.h>

int main() {
    
    
    int t, n, i, j, k, vetor[10000], menor;
    
    scanf("%d", &t);
    if(t>=1 && t<=10) {
        
        for(i=0; i<t; i++) {
            
            scanf("%d", &n);
            if(n>=2 && n<=1000) {
                menor = 9999999;


                for(j=0; j<n; j++) {
                    scanf("%d", &vetor[j]);
                }
                for(j=0; j<n; j++) {
                    for(k=0; k<n; k++) {
                        if(j!=k) {
                            if(vetor[j]-vetor[k]<0) {
                                if(vetor[k]-vetor[j]<menor) {
                                    menor=vetor[k]-vetor[j];
                                }
                            } else {
                                if(vetor[j]-vetor[k]<menor) {
                                    menor=vetor[j]-vetor[k];
                                }
                            }
                        }
                    }
                }
                printf("%d %d\n", menor, n*n);                
            }
            
        }
    }

    return 0;
}