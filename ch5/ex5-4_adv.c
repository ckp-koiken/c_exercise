#include <stdio.h>

enum { NMAX = 100 };

int main(void) {
    int n, grams, median, apple[NMAX];
    double median_even;

    // 重さを配列に入力
    n = 0;
    printf("重さを入力してください（0で終了）\n");
    while (n < NMAX) {
        printf("重さ？");
        scanf("%d", &grams);
        if (grams == 0)
            break;
        apple[n] = grams;
        n++;
    }

    // ソートで軽い順に整列
    for (int i = 0; i <= n-2; i++) {
        int tmp;
        for (int j = i+1; j < n; j++) {
            if (apple[j] < apple[i]) {
                tmp = apple[i];
                apple[i] = apple[j];
                apple[j] = tmp;
            }
        }
    }

    // 中央値を求める
    if (n % 2 != 0) {
        // 要素数が奇数なら2で割った商番目が真ん中
        median = apple[n/2]; 
        printf("中央値 %d g\n", median);
    } else {
        // 要素数が偶数なら2で割った商-1番目とその隣を足して2で割る
        median_even = (apple[n/2-1] + apple[n/2]) / 2.0;
        printf("中央値 %.1lf g\n", median_even);
    }

    return 0;
}
