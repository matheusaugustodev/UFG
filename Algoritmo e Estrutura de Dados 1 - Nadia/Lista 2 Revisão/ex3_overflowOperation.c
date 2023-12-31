#include <stdio.h>

int main() {
    int max, n1, n2, result;
    char operator[1];

    scanf("%d", &max);
    scanf("%d %c %d", &n1, operator, &n2);

    if ((operator[0] == 'x' && n1*n2>max) || (operator[0] == '+' && n1+n2>max)) printf("overflow\n");
    else printf("no overflow\n");  

    return 0;
}