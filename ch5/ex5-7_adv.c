#include <stdio.h>

enum { N = 3 };

int main(void) {
    double d, a[N][N] = { {3.0, 0.0, 0.0}, {-4.0, -2.0, -3.0}, {-1.0, 0.0, -5.0} };
    d = 0;
    dp = 0;
    dm = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("% .1lf ", a[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        d = d + a[0][i] * a[1][(i+1)%3] * a[2][(i+2)%3] - a[0][i] * a[1][(i+2)%3] * a[2][(i+1)%3];
    }

    printf("行列式の値は%.1lf\n", d);


    return 0;
}
