#include <stdio.h>

int main()
{
    int n, leds[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, i, j, digito, total;
    char numero[1000];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", numero);

        total = 0;
        for (j = 0; numero[j] != '\0'; j++) {
            digito = numero[j] - '0';
            total += leds[digito];
        }

        printf("%d leds\n", total);
    }

    return 0;
}
