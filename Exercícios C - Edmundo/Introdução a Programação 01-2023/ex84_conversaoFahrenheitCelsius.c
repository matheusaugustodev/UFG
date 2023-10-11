#include <stdio.h>

int main() {

    double fahrenheit, celsius;
    int i = 1;
    int n;
    scanf("%d", &n);
    while (i<=n) {
        scanf("%lf", &fahrenheit);
        celsius = (5*(fahrenheit - 32))/9.00;
        printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", fahrenheit, celsius);
        i++;
    }
    return 0;
}
