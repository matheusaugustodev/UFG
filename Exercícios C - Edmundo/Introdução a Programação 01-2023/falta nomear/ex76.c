#include <stdio.h>
#include <string.h>

int main()
{
    int n, x, y, i, j, tamanho;
    char temp[12221], string[12221];
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        
        string[0] = '\0';

        for(j=x; j<=y; j++) {
            sprintf(temp, "%d", j);
            strcat(string, temp);
        }
        printf("%s", string);
        
        tamanho = strlen(string);
        for(j=tamanho-1; j>=0; j--) printf("%c", string[j]);
        
        printf("\n");
    }

    return 0;
}
