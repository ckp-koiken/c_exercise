#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *tnum, n;  // tnumがゼッケン番号の配列領域、nは競技者数
    double *qtime;  // タイムの配列領域

    printf("競技者数？");
    scanf("%d", &n);

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

    for (int i = 0; i < n; i++) {
        printf("ゼッケン番号？");
        scanf("%d", &tnum[i]);
        printf("#%dのタイム？", tnum[i]);
        scanf("%lf", &qtime[i]);
    }

    printf("--- 結果 ---\n");

    for (int i = 0; i < n; i++) {
        printf("#%d: %.3f秒\n", tnum[i], qtime[i]);
    }

    // ゼッケン番号とタイムの領域解放
    free(tnum);
    free(qtime);

    return 0;
}