#include <stdio.h>

int main(void) {
    char str[] = "Hello!";
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    i--;        // ヌル文字の1字前の添え字に戻る

    while (i >= 0) {
        putchar(str[i]);
        i--;
    }

    putchar('\n');
    return 0;
}