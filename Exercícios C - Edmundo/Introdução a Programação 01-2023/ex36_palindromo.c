#include <stdio.h>

int main() {
    
    int num, inverso, x1, x2, x3, x4, x5;
    scanf("%i", &num);
    x1 = (num%10);
    x2 = (num%100)/10;
    x3 = (num%1000)/100;
    x4 = (num%10000)/1000;
    x5 = num/10000;
    
    if(num>99999) {
        printf("NUMERO INVALIDO\n");
    } else {
        if(num>9 && num<=99) {
            inverso = (x1*10)+x2;
        } else if (num>99 && num<=999) {
            inverso = (x1*100)+(x2*10)+x3;
        } else if (num>999 && num<=9999) {
            inverso = (x1*1000)+(x2*100)+(x3*10)+x4;
        } else if(num>9999) {
            inverso = (x1*10000)+(x2*1000)+(x3*100)+(x4*10)+x5;
        } else {
            inverso = x1;
        }
        if(num == inverso) {
            printf("PALINDROMO\n");
        } else {
            printf("NAO PALINDROMO\n");
        }
    }

    return 0;
}