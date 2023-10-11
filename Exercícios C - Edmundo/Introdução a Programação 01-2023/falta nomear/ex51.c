#include <stdio.h>

int main()
{
    int vetor[10000], n, i, frequencia, maior, indice, ultimo;
    
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
        if(i==n-1) {
           ultimo = vetor[i]; 
        }
    }
    maior = -999;
    for(i=0; i<n; i++) {
        if(vetor[i]>maior) {
            maior=vetor[i];
            indice = i;
        }
    }
    frequencia = 0;
    for(i=0; i<n; i++) {
        if(vetor[i]==ultimo) {
            frequencia++;
        }
    }
    printf("Nota %d, %d vezes\nNota %d, indice %d\n", ultimo, frequencia, maior, indice);




    return 0;
}