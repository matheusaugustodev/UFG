#include <stdio.h>
 
int main()
{
    
    int conta;
    float preco, consumo;
    char tipo[1];
    scanf("%i %f %c", &conta, &consumo, tipo);
    if(tipo[0]=='C') {
        if(consumo>80) {
            preco = 500+((consumo - 80)*0.25);
        } else {
            preco = 500;
        }
    } else if (tipo[0]=='R') {
        preco = 5 + (consumo*0.05);
    } else {
        if(consumo>100) {
            preco = 800+((consumo - 100)*0.04);
        } else {
            preco = 800;
        }
    }
    printf("CONTA = %i\nVALOR DA CONTA = %.2f\n", conta, preco);
    
    return 0;
}