#include <stdio.h>
#include <conio.h>

int countSequences(int n) {
    int MOD = 12345;
    int f1 = 2, f2 = 4, f3 = 7;
    if (n == 1) return f1;
    if (n == 2) return f2;
    if (n == 3) return f3;

    for (int i = 4; i <= n; i++) {
        int f = (f1 + f2 + f3) % MOD;
        f1 = f2;
        f2 = f3;
        f3 = f;
    }
    return f3;
}

int main () {
    int n;
    // \033[1;32m - Зелений колір
    // \033[1;31m - Червоний колір
    // \033[0m - Скинути до звичайного кольору
    do {
        printf("\033[1;32mEnter the length of the sequence \033[1;31mn: ");
        scanf ("%d", &n);
        if (n <= 1) {
            printf ("\033[1;31mn\033[1;32m must be greater than 1\033[0m\n");
        }
        if (n >= 10000) {
            printf ("\033[1;31mn\033[1;32m must be less than 10000\033[0m\n");
        }
    } while (n <= 1 || n >= 10000);
    printf("\033[1;32mNumber of searched sequences: \033[1;31m%d", countSequences(n));

    printf("\033[0m\n");
    printf ("Press any key to exit the program.");
    getch();
    return 0;
}