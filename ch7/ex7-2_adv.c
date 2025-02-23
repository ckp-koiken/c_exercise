#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c, n;

    n = 0;
    while ((c = getchar()) != EOF) {
        if (isupper(c) != 0)
            n++;
    }
    printf("大文字は%d個ありました\n", n);
    return 0;
}