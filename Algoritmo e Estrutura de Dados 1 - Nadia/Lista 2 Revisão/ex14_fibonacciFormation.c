#include <stdio.h>
#include <gmp.h>

int main() {
    int i, j, k, n, y, z;
    mpz_t fibonacci[101];
    mpz_t temp, x;

    for (i = 0; i <= 100; i++) {
        mpz_init(fibonacci[i]);
    }

    mpz_init(temp);
    mpz_init(x);

    mpz_set_ui(fibonacci[0], 0);
    mpz_set_ui(fibonacci[1], 1);

    for (i = 2; i <= 100; i++) {
        mpz_add(fibonacci[i], fibonacci[i - 1], fibonacci[i - 2]);
    }

    scanf("%d", &k);

    for (i = 0; i < k; i++) {
        scanf("%d", &n);

        mpz_set_ui(x, 2);
        y = 0;
        mpz_set(temp, fibonacci[n]);

        while (mpz_cmp(x, temp) <= 0) {
            if (mpz_divisible_p(temp, x)) {
                mpz_set(fibonacci[y], x);
                mpz_divexact(temp, temp, x);
                y++;
            } else {
                mpz_add_ui(x, x, 1);
            }
        }

        for (z = 0; z < y; z++) {
            mpz_out_str(stdout, 10, fibonacci[z]);
            if (z == y - 1) printf("\n");
            else printf(" ");
        }
    }

    for (i = 0; i <= 100; i++) {
        mpz_clear(fibonacci[i]);
    }
    mpz_clear(temp);
    mpz_clear(x);

    return 0;
}
