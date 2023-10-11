#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, i, j;
    
    scanf("%d", &n);
    getchar();
    
    if(n>10000) return 0;
    
    for(i=0; i<n; i++) {
        char string[1000], temp;

        scanf("%[^\n]", string);
        getchar();
        
        if(strlen(string) > 1000) return 0;
        
        for(j=0; j<strlen(string); j++) {
            if((string[j]>=48 && string[j]<=57) || (string[j]>=65 && string[j]<=90) || (string[j]>=97 && string[j]<=122))
                string[j] = string[j] + 3;
        }
        for(j=0; j<strlen(string); j += 2) {
            if(j != strlen(string) - 1) {
                temp = string[j];
                string[j] = string[j+1];
                string[j+1] = temp;
            }
        }
        for(j=0; j<strlen(string); j++) {
            if(string[j] == '+') string[j] = ' ';
            else if(string[j] == ' ') string[j] = '+';
            printf("%c", string[j]);
        }          
        printf("\n");
        
    }
    
    return 0;
}
