#include <stdio.h>

enum { N = 3 };

int main(void) {
    int a[N][N] = { {0} };
    int i, j, n, sum, nexti, nextj;

    // 魔法陣を作る
    j = 0;
    j = N / 2;
    for (n = 1; n <= N * N; n++) {
        a[i][j] = n;
        // 右上の位置をnexti, nextjに求める
        if ((nexti = i - 1) < 0)
            nexti = N - 1;
        if ((nextj = j + 1) >= N)
            nextj = 0;

        // 右上に行くか下に行くかの判断
        if (a[nexti][nextj] == 0) {
            i = nexti;
            j = nextj;
        } else {
            if (++i >= N)
             i = 0;
        }
    }

    // できた魔法陣を表示する
    for (i = 0; i < N; i++) {
        printf("+");
        for (j = 0; j < N; j++)
            printf("---+");
        printf("\n|");
        for (j = 0; j < N; j++)
            printf("%3d|", a[i][j]);
        printf("\n");
    }
    printf("+");
    for (j = 0; j < N; j++)
        printf("---+");
    printf("\n");
    return 0;
}
