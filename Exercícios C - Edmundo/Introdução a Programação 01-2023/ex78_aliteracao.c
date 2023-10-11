#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k=0, aliteracao=0;
    char string[5000], iniciais[5000];

    while (scanf("%[^\n]", string) != EOF) {
        getchar();

        k = 0;
        aliteracao = 0;

        for(i=0; i<strlen(string); i++) {
            if(i==0 || string[i-1] == ' ') {
                iniciais[k]=string[i];
                k++;
            }
        }

        for(i=0; i<k; i++)
            if(iniciais[i] < 91 && iniciais[i] > 64) iniciais[i]+=32;

        for(i=0; i<k; i++) {
            if(i>0) {
                if (iniciais[i] == iniciais[i+1] && iniciais[i] != iniciais[i-1]) aliteracao++;  
            } else if (iniciais[i] == iniciais[i+1]) aliteracao++;
        }

        printf("%d\n", aliteracao);
    }
    
    return 0;
}