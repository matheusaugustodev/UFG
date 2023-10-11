#include <stdio.h>

int main()
{
    int vetor[1000000], n, i, j, temp;
    float valorMediana;
    
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        vetor[i] = 0;
    }
    for(i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
    }
    
    for(i=0; i<n-1; i++) {
        for(j= i+1; j<n; j++) {
            if(vetor[j] < vetor[i]) {
                temp = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = temp;
            }
        }
    }
    
    if(n%2==0) {
        valorMediana = (vetor[((n-1)/2)]+vetor[((n-1)/2)+1])/2.00;
    } else {
        valorMediana = vetor[n/2];
    }
    printf("%.2f\n", valorMediana);

    
    
    return 0;
}