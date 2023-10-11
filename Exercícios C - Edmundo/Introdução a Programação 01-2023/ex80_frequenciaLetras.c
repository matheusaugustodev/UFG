#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char string[201];
    int frequencia[26] = {0};
    int i, j, maxFreq;
    char caractere;

    scanf("%d\n", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%[^\n]", string);
        getchar();

        for (j = 0; j < 26; j++) {
            frequencia[j] = 0; 
        }

        for (j = 0; j < strlen(string); j++) {
            caractere = string[j];
            if ((caractere >= 'a' && caractere <= 'z') || (caractere >= 'A' && caractere <= 'Z')) {
                if (caractere >= 'A' && caractere <= 'Z') {
                    caractere = caractere - 'A' + 'a';
                }
                frequencia[caractere - 'a']++; 
            }
        }

        maxFreq = 0;
        for (j = 0; j < 26; j++) {
            if (frequencia[j] > maxFreq) {
                maxFreq = frequencia[j];
            }
        }

        for (j = 0; j < 26; j++) {
            if (frequencia[j] == maxFreq) {
                printf("%c", j + 'a'); 
            }
        }
        printf("\n");
    }

    return 0;
}
