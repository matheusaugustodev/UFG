#include <stdio.h>
#include <string.h>

#define MAX_DIGITOS 40
#define MAX_RESULTADO (2 * MAX_DIGITOS)

void multiplicar(char m[MAX_DIGITOS], char n[MAX_DIGITOS], char resultado[MAX_RESULTADO]) {
    int i, j, k;
    int len_m = strlen(m);
    int len_n = strlen(n);

    for (i = 0; i < MAX_RESULTADO; i++) {
        resultado[i] = '0';
    }

    for (i = len_m - 1; i >= 0; i--) {
        int carry = 0;
        for (j = len_n - 1, k = len_m - 1 - i; j >= 0; j--, k++) {
            int temp = (m[i] - '0') * (n[j] - '0') + (resultado[k] - '0') + carry;
            carry = temp / 10;
            resultado[k] = (temp % 10) + '0';
        }
        while (carry > 0) {
            int temp = (resultado[k] - '0') + carry;
            carry = temp / 10;
            resultado[k++] = (temp % 10) + '0';
        }
    }

    while (k > 0 && resultado[k - 1] == '0') {
        k--;
    }

    for (i = 0, j = k - 1; i < j; i++, j--) {
        char temp = resultado[i];
        resultado[i] = resultado[j];
        resultado[j] = temp;
    }

    resultado[k] = '\0';
}

int main() {
    int t, caso;
    scanf("%d", &t);

    for (caso = 0; caso < t; caso++) {
        char m[MAX_DIGITOS], n[MAX_DIGITOS], resultado[MAX_RESULTADO];

        scanf("%s %s", m, n);

        multiplicar(m, n, resultado);

        printf("%s\n", resultado);
    }

    return 0;
}
