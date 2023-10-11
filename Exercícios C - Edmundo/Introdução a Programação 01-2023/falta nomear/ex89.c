#include <stdio.h>

int main() {

    int matricula;
    double notaFinal, p1, p2, p3, p4, p5, p6, p7, p8, e1, e2, e3, e4, e5, trabalho, presenca;
    do {
        scanf("%d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &matricula, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &e1, &e2, &e3, &e4, &e5, &trabalho, &presenca);
        if(matricula!=-1 && p1 != -1 && p2 != -1 && p3 != -1 && p4 != -1 && p5 != -1 && p6 != -1 && p7 != -1 && p8 != -1 && e1 != -1 && e2 != -1 && e3 != -1 && e4 != -1 && e5 != -1 && trabalho != -1 && presenca) {
            notaFinal = (0.7*((p1+p2+p3+p4+p5+p6+p7+p8)/8))+(0.15*((e1+e2+e3+e4+e5)/5))+(0.15*trabalho);
            if(presenca<96 && notaFinal>=6) {
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: REPROVADO POR FREQUENCIA\n", matricula, notaFinal);
            } else if (presenca<96 && notaFinal<6) {
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: REPROVADO POR NOTA E POR FREQUENCIA\n", matricula, notaFinal);
            } else if (notaFinal<6 && presenca>=96) {
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: REPROVADO POR NOTA\n", matricula, notaFinal);
            } else {
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: APROVADO\n", matricula, notaFinal);
            }
        }
    }
    while (matricula!=-1 && p1 != -1 && p2 != -1 && p3 != -1 && p4 != -1 && p5 != -1 && p6 != -1 && p7 != -1 && p8 != -1 && e1 != -1 && e2 != -1 && e3 != -1 && e4 != -1 && e5 != -1 && trabalho != -1 && presenca);
    

    return 0;
}
