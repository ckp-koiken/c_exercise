#include <stdio.h>

int main(void) {
    int c, n;

    n = 0;
    while ((c = getchar()) != EOF) {
        if (65 <= c && c < 90)
            n++;
    }
    printf("大文字は%d個ありました\n", n);
    return 0;
}