#include <stdio.h>

int main()
{
    int n, k, i, j, vetor[1001], m, presente[1001];
    scanf("%d %d", &n, &k);
    m=0;
    j=0;
    for(i=1; i<=n; i++) {
        scanf("%d", &vetor[i]);
        if(vetor[i]<=0) {
            m++;
            presente[j]=i;
            j++;
        }
    }
    if(m>=k) {
        printf("NAO\n");
        j--;
        for(j; j>=0; j--) {
            printf("%d\n", presente[j]);
        }
    } else {
        printf("SIM\n");
    }

    return 0;
}
