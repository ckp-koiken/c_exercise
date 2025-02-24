#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c, lf;

    while ((c = getchar()) != EOF) {
        if (c == '.' || c == '?' || c == '!') {
            lf = c;
            while (lf == '\n') {
                if (lf != '\n') {
                    putchar(lf);
                } else { // TODO: <== の表示を改善
                    putchar(' ');
                    putchar('<');
                    putchar('=');
                    putchar('=');
                    putchar(' ');
                }
                lf = c;
            }
        } else {
            putchar(c);
        }
    }
    printf("\n");
    return 0;
}