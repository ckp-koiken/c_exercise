#include <stdio.h>
#include <ctype.h>

#define KEY 1

int main(void) {
    int c, cipher;

    while ((c = getchar()) != EOF) {
        if (islower(c)) {
            cipher = (c - 97 + KEY) % 26 + 97;
            putchar(cipher);
        } else 
            putchar(c);
    }
    return 0;
}