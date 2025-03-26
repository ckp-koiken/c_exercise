#include <stdio.h>

#define EPSILON 0.00001

int main(void) {
    double s;
    int i;

    // s = 1;
    // i = 1;
    // while (1.0 / (i * 2 - 1) > EPSILON) {
    //     i++;
    //     if (i % 2 == 1) {
    //         s = s + 1.0 / (i * 2 - 1);
    //     } else {
    //         s = s - 1.0 / (i * 2 - 1);
    //     }
    // }

    s = 0;
    i = 1;
    for (;;) {
        if (i % 2 == 1) {
            s = s + 1.0 / (i * 2 - 1);
        } else {
            s = s - 1.0 / (i * 2 - 1);
        }

        if (1.0 / (i * 2 - 1) < EPSILON) break;
        i++;
    }

    printf("%lf * 4 = %lf\n", s, s * 4);

    return 0;
}