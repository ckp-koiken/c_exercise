#include <stdio.h>

enum { N = 3 };

int main(void) {
    int a[N][N] = { {0} };
    int i, j, n, nexti, nextj;

    // 魔法陣を作る
    i = 0;
    j = N / 2;
    for (n = 1; n <= N * N; n++) { // 1からN*Nまで
        a[i][j] = n;                // 添え字iとjにnを配置する
        // 右上の位置をnexti, nextjに求める
        nexti = i - 1; // 行を上にずらす
        nextj = j + 1; // 列を右隣にずらす
        if (nexti < 0)
            nexti = N - 1;  // もし上の行が無ければ一番下の行に移す
        if (nextj >= N)
            nextj = 0;  // もし右隣が無ければ一番左の列に移す

        // 右上に行くか下に行くかの判断
        if (a[nexti][nextj] == 0) {
            i = nexti;  // そのマスに0が入っていればそのまま数を入れる
            j = nextj;
        } else {
            i++; // そのマスに数が入っていれば下の行にずらす
            if (i >= N)  // 一番下の行を超えるようであれば一番上に戻す
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
