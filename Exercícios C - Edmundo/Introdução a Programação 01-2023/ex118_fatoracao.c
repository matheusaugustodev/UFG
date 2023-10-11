#include <stdio.h>

int main()
{
    int n, temp, i=2, j=0, fatores[1000];
    
    scanf("%d", &n);
    while(n<=1)  {
        printf("Fatoracao nao e possivel para o numero %d!\n", n);
        scanf("%d", &n); 
    }
    
    temp = n;
    while(i*i<=n) {
        if(temp%i == 0) {
            fatores[j]=i;
            j++;
            temp = temp/i;
        } else i++;
    } 

    if(temp>1) {
        fatores[j] = temp;
        j++;
    }
    
    printf("%d =", n);
    for(i=0; i<j; i++) {
        if(i==j-1) printf(" %d", fatores[i]);
        else printf(" %d x", fatores[i]);
    }
    printf("\n");

    return 0;
}
