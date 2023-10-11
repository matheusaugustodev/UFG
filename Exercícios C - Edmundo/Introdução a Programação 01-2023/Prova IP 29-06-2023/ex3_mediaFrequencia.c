#include <stdio.h>

int main()
{
    int i, n, vetor[10000], maior1 = 0, maior2 = 0;
    float media=0;
    
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
        media += vetor[i];
    }
    media = media/n;
    
    if(n<6) {
        printf("QUANTIDADE DE ELEMENTOS INVALIDOS!\n");
        return 0;
    }
    
    for(i=0; i<n/2; i++) if(vetor[i] > media) maior1++;
    for(i=(n/2)+1; i<n; i++) if(vetor[i] > media) maior2++;
    
    if(maior1 > maior2) printf("%.2f %d %d PRIMEIRA METADE\n", media, maior1, maior2);
    else if(maior1 < maior2) printf("%.2f %d %d  SEGUNDA METADE\n", media, maior1, maior2);
    else printf("%.2f %d %d EMPATE\n", media, maior1, maior2);
    
    return 0;
}
