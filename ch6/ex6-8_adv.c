#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *tnum, n, i;  // tnumがゼッケン番号の配列領域、nは競技者数
    double *qtime;  // タイムの配列領域

    // 適当な大きさの領域を確保
    n = 5;

    // ゼッケン番号の領域確保
    if ((tnum = malloc(sizeof(int)*n)) == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // タイムの領域確保
    if ((qtime = malloc(sizeof(double)*n)) == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (i >= 0) {
        // mallocで確保した数(n)を超えて領域が必要なとき
        // i+1(i=0スタートのため)分の領域をreallocで再確保する
        if (i >= n) {
            tnum = realloc(tnum, sizeof(int)*(i+1));
            if (tnum == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
            qtime = realloc(qtime, sizeof(double)*(i+1));
            if (qtime == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        printf("ゼッケン番号？");
        scanf("%d", &tnum[i]);
        if (tnum[i] < 0)
            break;
        printf("#%dのタイム？", tnum[i]);
        scanf("%lf", &qtime[i]);
        i++;
    }

    printf("--- 結果 ---\n");

    for (int j = 0; j < i; j++) {
        printf("#%d: %.3f秒\n", tnum[j], qtime[j]);
    }

    // ゼッケン番号とタイムの領域解放
    free(tnum);
    free(qtime);

    return 0;
}