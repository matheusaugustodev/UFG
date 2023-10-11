#include <stdio.h>
#include <string.h>

int main()
{

    int n, i, j, tamanho;
    char string[1000], temp[1000];
    scanf("%d", &n);
    getchar();
    
    if(n<1 || n>10000) {
        return 0;
    }
    
    for (i=0; i<n; i++) {
        scanf("%[^\n]", string);
        getchar();
        tamanho = strlen(string);
        
        for(j=0; j<tamanho; j++) {
            if((string[j]>='a' && string[j]<='z') || (string[j]>='A' && string[j]<='Z')) {
                string[j] = string[j] + 3;
            }
        }
        for(j=0; j<tamanho; j++) {
            temp[j] = string[tamanho-1-j];
        }
        for(j=tamanho/2; j<tamanho; j++) {
            temp[j] = temp[j] - 1;
        }
        temp[tamanho] = '\0';
        printf("%s\n",temp);
    }

    return 0;
}