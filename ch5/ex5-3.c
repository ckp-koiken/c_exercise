#include <stdio.h>

enum { NMAX = 100 };

int main(void) {
    int i, n, grams, apple[NMAX];
    double sum, ave;

    n = 0;
    printf("重さを入力してください（0で終了）\n");

    // 配列入力
    while (n < NMAX) {
        printf("重さ？");
        scanf("%d", &grams);
        if (grams == 0)
            break;
        // apple[n++] = grams; // ポストインクリメント、nが式で使われた後にインクリメントされる 
        apple[n] = grams;
        n++;
    }

    // 平均算出
    sum = 0;
    for (int i = 0; i < n; i++)
        sum += apple[i];
    ave = sum / n;
    printf("平均%.1fグラム\n平均以上の重さのもの", ave);

    // 平均以上を判定
    for (int i = 0; i < n; i++)
        if (apple[i] >= ave)
            printf(" %d", apple[i]);
    
    printf("\n");

    return 0;
}
