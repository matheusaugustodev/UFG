#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char string[1000], x[1000], y[1000];
    int i, j=0, k=0, contador=0, freq[9];
    float distancia;
    

    scanf("%[^\n]", string);

    for(i=0; i<strlen(string); i++) {
        if(string[i]==';') contador++;
    }
    if(contador!=1) {
        printf("FORMATO INVALIDO!\n");
        return 0;
    }
    
    for(i=0; i<10; i++) {
        freq[i] = 0;
    }

    i=0;
    while (string[i] != ';') {
        x[j] = string[i];
        j++;
        i++;
    }
    i++;
    for (; i < strlen(string); i++) {
        y[k] = string[i];
        k++;
    }
    
    for(i=0; i<strlen(x); i++) {
        if(x[i]=='a'||x[i]=='A') freq[0]++;
        if(x[i]=='e'||x[i]=='E') freq[1]++;
        if(x[i]=='i'||x[i]=='I') freq[2]++;
        if(x[i]=='o'||x[i]=='O') freq[3]++;
        if(x[i]=='u'||x[i]=='U') freq[4]++;
    }
    for(i=0; i<strlen(y); i++) {
        if(y[i]=='a'||y[i]=='A') freq[5]++;
        if(y[i]=='e'||y[i]=='E') freq[6]++;
        if(y[i]=='i'||y[i]=='I') freq[7]++;
        if(y[i]=='o'||y[i]=='O') freq[8]++;
        if(y[i]=='u'||y[i]=='U') freq[9]++;
    }
    distancia = sqrt((freq[0]-freq[5])*(freq[0]-freq[5]) + (freq[1]-freq[6])*(freq[1]-freq[6]) +(freq[2]-freq[7])*(freq[2]-freq[7]) + (freq[3]-freq[8])*(freq[3]-freq[8]) + (freq[4]-freq[9])*(freq[4]-freq[9]));

    printf("(%d,%d,%d,%d,%d)\n", freq[0], freq[1], freq[2], freq[3], freq[4]);
    printf("(%d,%d,%d,%d,%d)\n", freq[5], freq[6], freq[7], freq[8], freq[9]);
    printf("%.2f\n", distancia);
    

    return 0;
}
