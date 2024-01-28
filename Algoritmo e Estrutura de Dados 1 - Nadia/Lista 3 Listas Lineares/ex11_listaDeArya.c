#include <stdio.h>

int main() {
    int n, i, j, lista[1001], qtd, p, e;
    char op;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &lista[i]);
    }

    while (1) {
        scanf(" %c", &op);

        if (op == 'F') {
            printf("fim\n");
            break;
        } else if (op == 'I') {
            scanf("%d %d", &p, &e);

            for (i = 1; i <= n; i++) {
                if (lista[i] == e) {
                    for (j = n + 1; j > i; j--) {
                        lista[j] = lista[j - 1];
                    }
                    lista[i + 1] = p;
                    n++;
                    printf("inserido %d\n", p);
                    break;
                }
            }
        } else if (op == 'R') {
            scanf("%d", &p);

            for (i = 1; i <= n; i++) {
                if (lista[i] == p) {
                    for (j = i; j < n; j++) {
                        lista[j] = lista[j + 1];
                    }
                    n--;
                    printf("removido %d\n", p);
                    break;
                }
            }
        } else if (op == 'C') {
            scanf("%d %d", &p, &e);
            int qtd = 0;
            int found_p = 0;
            int found_e = 0;

            for (i = 1; i <= n; i++) {
                if (lista[i] == p) {
                    found_p = 1;
                } else if (lista[i] == e) {
                    found_e = 1;
                }

                if (found_p && !found_e) {
                    qtd++;
                }
            }

            if (qtd-1 >= 0) qtd--;
            printf("quantidade %d\n", qtd);
        } else if (op == 'M') {
            if (n == 0) {
                printf("lista vazia\n");
            } else {
                for (i = 1; i <= n; i++) {
                    printf("%d ", lista[i]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
