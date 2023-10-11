#include <stdio.h>

int main() {
    
    int n, i, j, equipes[101], pontuacao[101], temp, temp2;
    
    scanf("%d", &n);
    
    if(n<6 || n>100) {
        printf("CAMPEONATO INVALIDO!\n");
        return 0;
    }    
    
    for(i=0; i<n; i++) scanf("%d", &equipes[i]);
    for(i=0; i<n; i++) scanf("%d", &pontuacao[i]);
    
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(j!=i) {
                if (pontuacao[i] > pontuacao[j] || (pontuacao[i] == pontuacao[j] && equipes[i] < equipes[j])) {
                    temp = pontuacao[j];
                    pontuacao[j] = pontuacao[i];
                    pontuacao[i] = temp;
                    
                    temp2 = equipes[j];
                    equipes[j] = equipes[i];
                    equipes[i] = temp2;
                }
            }
        }
    }

    for(i=0; i<n; i++) printf("%d %d %d\n", i+1, equipes[i], pontuacao[i]);


    return 0;
}
