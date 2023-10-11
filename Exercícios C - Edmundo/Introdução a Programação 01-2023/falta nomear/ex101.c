#include <stdio.h>

int main() {

    float valorIngresso, valorInicial, valorFinal, lucro, valor1, lucro1;
    int numeroIngressos,numeroIngressos1, i;

    scanf("%f", &valorIngresso);
    scanf("%f", &valorInicial);
    scanf("%f", &valorFinal);

    lucro1 = 0;
    if(valorInicial>=valorFinal) {
        printf("INTERVALO INVALIDO.\n");
    } else {
        for(valorInicial; valorInicial<=valorFinal; valorInicial++) {
            i= (valorIngresso-valorInicial)/0.5;
            if(valorInicial==valorIngresso) {
                numeroIngressos = 120;
                lucro = (120*valorInicial - (200+0.05*120));
            } else if(valorInicial<valorIngresso) {
                numeroIngressos = (120+25*i);
                lucro= (valorInicial*numeroIngressos-(200+0.05*numeroIngressos));
            } else {
                numeroIngressos = (120+30*i);
                lucro= (valorInicial*numeroIngressos-(200+0.05*numeroIngressos));
            }
            if(lucro>lucro1) {
                lucro1=lucro;
                valor1=valorInicial;
                numeroIngressos1=numeroIngressos;
            }
            printf("V: %.2f, N: %d, L: %.2f\n", valorInicial, numeroIngressos, lucro);
        }
        printf("Melhor valor final: %.2f\n", valor1);
        printf("Lucro: %.2f\n", lucro1);
        printf("Numero de ingressos: %d\n", numeroIngressos1);

    }

    return 0;
}
