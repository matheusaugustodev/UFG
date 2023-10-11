#include <stdio.h>
#include <string.h>

int main()
{

    int n, i, j, vogais, consoantes;
    char frase[10000];
    
    scanf("%d", &n);
    getchar();
    for (i=0; i<n; i++) {
        scanf("%[^\n]", frase);
        getchar();
        vogais=0;
        consoantes=0;
        for(j=0; j<strlen(frase); j++) {
             if((frase[j]>='a' && frase[j]<='z') || (frase[j]>='A' && frase[j]<='Z')) {
                if(frase[j]=='a' || frase[j]=='e' || frase[j]=='i' || frase[j]=='o' || frase[j]=='u' || frase[j]=='A' || frase[j]=='E' || frase[j]=='I' || frase[j]=='O' || frase[j]=='U') vogais++;
                else consoantes++;
             }
        }
        printf("Letras = %d\nVogais = %d\nConsoantes = %d\n", vogais+consoantes, vogais, consoantes);
    }

    return 0;
}