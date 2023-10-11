#include <stdio.h>

int main()
{
    int i;
    float a, b, c, temp;
    scanf("%d %f %f %f", &i, &a, &b, &c);
    if(a>b) {
        temp = a;
        a = b;
        b = temp;
    }
    if(a>c) {
        temp = a;
        a = c;
        c = temp; 
    } 
    if(b>c) {
        temp = b;
        b = c;
        c = temp;
    }
    if(i==1) {
        printf("%.2f %.2f %.2f\n", a, b, c);
    } else if(i==2) {
        printf("%.2f %.2f %.2f\n", c, b, a);       
    } else {
        printf("%.2f %.2f %.2f\n", b, c, a);
    }

    return 0;
}
