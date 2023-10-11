#include <stdio.h>

int main()
{
    int hora, minuto, segundo, total;
    scanf("%i %i %i", &hora, &minuto, &segundo);
    total = hora*60*60 + minuto*60 + segundo;
    printf("O TEMPO EM SEGUNDOS E = %i\n", total);

    return 0;
}
