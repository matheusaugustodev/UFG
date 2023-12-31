#include <stdio.h>

int main() {
    int year, next, first=10;

    scanf("%d", &year);

    next = ((year-first)/76)*76+10+76;
    printf("%d\n", next);

    return 0;
}