#include <stdio.h>

int main()
{
    int n, i, j, k, x, temp, vetor[100000], par[100000], impar[100000];
    scanf("%d", &n);

    j=0;
    k=0;
    for(i=0; i<n; i++) {
        scanf("%d", &vetor[i]);
        if(vetor[i]%2==0) {
            par[j] = vetor[i];
            j++;
        } else {
            impar[k] = vetor[i];
            k++;
        }
    }
    for(i=1; i<j; i++) {
        for(x=0; x<j; x++) {
            if(par[x]>par[i]) {
                temp = par[x];
                par[x] = par[i];
                par[i] = temp;
            }
        }
    }
    for(i=1; i<k; i++) {
        for(x=0; x<k; x++) {
            if(impar[i]>impar[x]) {
                temp = impar[i];
                impar[i] = impar[x];
                impar[x] = temp;
            }
        }
    }
    for(i=0; i<j; i++) {
        printf("%d\n", par[i]);
    }
    for(i=0; i<k; i++) {
        printf("%d\n", impar[i]);
    }
    return 0;
}
