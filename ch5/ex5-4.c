#include <stdio.h>

enum { NMAX = 100 };

int main(void) {
    int n, grams, apple[NMAX];

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
    
    // ソートで整列
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

    // 別解
    // for (int i = 0; i <= n-2; i++) {
    //     int min, tmp;
    //     min = i;
    //     for (int j = i+1; j < n; j++) {
    //         if (apple[j] < apple[i])
    //             min = j;
    //     }
    //     tmp = apple[i];
    //     apple[i] = apple[min];
    //     apple[min] = tmp;
    // }

    // 表示
    for (int i = 0; i < n; i++)
        printf("%d ", apple[i]);
    printf("\n");

    return 0;
}
