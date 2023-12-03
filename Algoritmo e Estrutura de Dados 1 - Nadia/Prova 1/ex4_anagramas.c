#include <stdio.h>
#include <string.h>

void trocarPosicaoCaracteres(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void gerarAnagramas(char *string, int inicio, int ultimaPosicao) {

    int i;

    if (inicio == ultimaPosicao) {
        printf("%s\n", string);
        return;
    }

    for (i = inicio; i <= ultimaPosicao; i++) {
        // Evitar troca de caracteres iguais
        if (i != inicio && string[i] == string[inicio]) continue;

        // Trocar os caracteres
        trocarPosicaoCaracteres(&string[inicio], &string[i]);

        // Chamar recursivamente para o restante da string
        gerarAnagramas(string, inicio + 1, ultimaPosicao);

        // Desfazer a troca para a próxima iteração
        trocarPosicaoCaracteres(&string[inicio], &string[i]);
    }
}

int main() {
    char cadeia[257];
    int i, j, tamanhoCadeia;

    scanf("%256s", cadeia);

    // Ordenar a cadeia para ter ordem alfabética

    tamanhoCadeia = strlen(cadeia);

    for (i=0; i < tamanhoCadeia-1; i++) {
        for (j=i+1; j < tamanhoCadeia; j++) {
            if (cadeia[i] > cadeia[j]) {
                trocarPosicaoCaracteres(&cadeia[i], &cadeia[j]);
            }
        }
    }

    gerarAnagramas(cadeia, 0, tamanhoCadeia - 1);

    return 0;
}
