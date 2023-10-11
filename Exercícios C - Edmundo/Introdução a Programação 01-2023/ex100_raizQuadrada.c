#include <stdio.h>

int main()
{
    double n, r, ra, e, ei;
    scanf("%lf", &n);
    scanf("%lf", &ei);
    e = 1;
    r = 1;
    while (e > ei) {
        ra = (r + (n / r)) / 2.0;
        e = (ra * ra) - n;
        printf("r: %.9lf, err: %.9lf\n", ra, e);
        r = ra;
    }

    return 0;
}