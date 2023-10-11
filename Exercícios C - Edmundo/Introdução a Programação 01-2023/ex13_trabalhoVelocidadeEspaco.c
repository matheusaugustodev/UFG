#include <stdio.h>
#include <math.h>

int main() {
    
    double massa, aceleracao, tempo, velocidade, comprimento, trabalho;
    scanf("%lf %lf %lf", &massa, &aceleracao, &tempo);
    velocidade = aceleracao*tempo;
    comprimento = (aceleracao*(tempo*tempo))/2;
    trabalho = ((massa*1000)*(velocidade*velocidade))/2;
    printf("VELOCIDADE = %.2lf\n", velocidade*3.6);
    printf("ESPACO PERCORRIDO = %.2lf\n", comprimento);
    printf("TRABALHO REALIZADO = %.2lf\n", trabalho);

    return 0;
}
