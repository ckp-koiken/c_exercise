#include <stdio.h>

int main(void) {
    int c, f;
    printf("  C   F\n");
    // for (c = -20; c <= 100; c += 10) {
    //     f = 9*c/5 + 32;
    //     printf("%3d %3d\n", c, f);
    // }
    c = -20;
    while (c <= 100) {
        f = 9*c/5 + 32;
        printf("%3d %3d\n", c, f);
        c += 10;
    }
    return 0;
}
