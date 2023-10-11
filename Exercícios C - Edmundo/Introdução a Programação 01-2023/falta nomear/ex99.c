#include <stdio.h>

int main() {

    int matricula;
    float horas, valorPorHora, salario;
    
    do {
        scanf("%d %f %f", &matricula, &horas, &valorPorHora);
        printf("\n");
        if(matricula!=0 && horas!=0 && valorPorHora!=0) {
            printf("%d %.2f\n", matricula, horas*valorPorHora);
        }
    } while(matricula!=0 && horas!=0 && valorPorHora!=0); 


    return 0;
}
