#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            putchar('[');
            putchar(' ');
            putchar(']');
        } else
            putchar(c);
    }
    printf("\n");
    return 0;
}