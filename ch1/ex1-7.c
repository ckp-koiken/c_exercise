#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, n;

    for (i = 0; i < 5; i++) {
        n = rand();
        printf("%d\n", n);
    }
    printf("%d = RAND_MAX\n", RAND_MAX);
    return 0;
}
