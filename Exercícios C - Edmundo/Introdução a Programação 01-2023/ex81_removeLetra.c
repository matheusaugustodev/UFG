#include <stdio.h>
#include <string.h>

void str_clean(char str[], char clr[]);

int main()
{
    char str[256];
    char clr[256];

    scanf("%[^\n]", str);
    scanf("\n%[^\n]", clr);

    str_clean(str, clr);
    printf("%s\n", str);

    return 0;
}

void str_clean(char str[], char clr[])
{
    int i=0, j=0, k=0, encontrou=0;

    for (i=0; i<strlen(str); i++) {
        encontrou = 0;
        for (j=0; j<strlen(clr); j++) {
            if (str[i] == clr[j]) {
                encontrou = 1;
            }
        }
        if (encontrou == 0) {
            str[k] = str[i];
            k++;
        }
    }
    str[k] = '\0';

}