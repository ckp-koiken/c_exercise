#include <stdio.h>

#define EPSILON 0.00001

int main(void) {
    int n;
    double s;

    // TODO: snとsn-1の差でループを止めるように改善
    s = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (i % 2 == 1) {
            s = s + 1.0/(i*2-1);
        } else {
            s = s - 1.0/(i*2-1);
        }
    }
    printf("%lf * 4 = %lf\n", s, s*4);

    return 0;
}