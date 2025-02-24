#include <stdio.h>
#include <ctype.h>

#define KEY 1

void change_c(unsigned char letter);

void change_c(unsigned char letter) {
    int cipher;
    if (islower(letter)) {
        cipher = (letter - 97 + KEY) % 26 + 97;
        putchar(cipher);
    } else 
        putchar(letter);
}

int main(void) {
    int c;

    while ((c = getchar()) != EOF)
        change_c(c);
    return 0;
}