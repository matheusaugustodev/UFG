#include <stdio.h>

int main() {
    int matricula, dependentes;
    float salarioMinimo, salario, normal, liquido, bruto;
    scanf("%i %f %i %f %f", &matricula, &salarioMinimo, &dependentes, &salario, &normal);
    normal = (normal/100)*salario;

    if(salario > (12*salarioMinimo)) {
        bruto = (0.2*salario);
        liquido = bruto - (dependentes*300);
    } else if(salario > (5*salarioMinimo)) {
        bruto = (0.08*salario);
        liquido = (0.08*salario) - (dependentes*300);
    } else {
        bruto = 0;
        liquido = bruto - (dependentes*300);
    }
    printf("MATRICULA = %i\nIMPOSTO BRUTO = %.2f\nIMPOSTO LIQUIDO = %.2f\nRESULTADO = %.2f\n", matricula, bruto, liquido, (liquido-normal));
    if((liquido - normal)>0) {
        printf("IMPOSTO A PAGAR\n");
    } else if((liquido - normal)<0){
        printf("IMPOSTO A RECEBER\n");
    } else {
        printf("IMPOSTO QUITADO\n");
    }

    return 0;
}
