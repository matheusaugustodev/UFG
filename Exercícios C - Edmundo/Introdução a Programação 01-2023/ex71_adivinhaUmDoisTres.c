#include <stdio.h>
#include <string.h>

int main()
{

    int n, i, j, dois, um;
    char palavra[5];
    
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%s", palavra);
        if(strlen(palavra)<4) {
            dois=0;
            um=0;
            
            if(palavra[0]=='t') dois++;
            if(palavra[1]=='w') dois++;
            if(palavra[2]=='o') dois++;
            if(palavra[0]=='o') um++;
            if(palavra[1]=='n') um++;
            if(palavra[2]=='e') um++;

            if(um>dois) printf("1");
            else printf("2");
        } else {
            printf("3");
        }
   
        printf("\n");
    }

    return 0;
}