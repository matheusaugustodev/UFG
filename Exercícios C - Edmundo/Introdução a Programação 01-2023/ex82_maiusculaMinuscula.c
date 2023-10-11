#include <stdio.h>
#include <string.h>

int main()
{
    int i, j = 1, k = 0, m;
    char string[51], resultado[2000];

    while (scanf("%[^\n]", string) != EOF) {
        getchar();

        for(i=0; i<strlen(string); i++) {
            if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
                if (j == 1) {
                    if (string[i] >= 'a' && string[i] <= 'z')
                        resultado[k] = string[i] - 32;
                    else
                        resultado[k] = string[i];
                    j *= -1;
                    k++;
                } else {
                    if (string[i] >= 'A' && string[i] <= 'Z')
                        resultado[k] = string[i] + 32;
                    else
                        resultado[k] = string[i];
                    j *= -1;
                    k++;
                }
            }
            else {
                resultado[k] = string[i];
                k++;
            }
        }
        resultado[k] = '\n';
        k++;
    }
    for (i = 0; i < strlen(resultado); i++) 
        printf("%c", resultado[i]);

    return 0;
}