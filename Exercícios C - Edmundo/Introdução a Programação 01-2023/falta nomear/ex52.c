#include <stdio.h>

int main()
{
    int vetor[1000], n, i, j, menor, indice, temp;
    
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
    }
    
    for(i=0; i<n; i++) {
        menor = vetor[i];
        indice = i;
        
        for(j=i+1; j<n; j++) {
            if(vetor[j]<menor) {
                menor = vetor[j];
                indice = j;
            }
        }
        temp = vetor[i];
        vetor[i] = vetor[indice];
        vetor[indice] = temp;
    }
    for(i=0; i<n; i++) {
        printf("%d\n", vetor[i]);
    }



    return 0;
}