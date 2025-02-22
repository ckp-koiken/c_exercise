#include <stdio.h>

int main(void) {
    for (int i = 32; i <= 126; i++) {
        printf("%3d %c ", i, i);
        if (i % 8 == 7)
            printf("\n");
    }
    printf("\n");
    return 0;
}