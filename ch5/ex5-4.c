#include <stdio.h>

enum { NMAX = 100 };

int main(void) {
    int i, n, grams, apple[NMAX];

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
    
    // 選択ソートで整列
    for (int i = 0; i <= n-2; i++) {
        int min, tmp;
        min = i;
        for (int j = i+1; j < n; j++) {
            if (apple[j] < apple[min])
                min = j;
        }
        tmp = apple[i];
        apple[i] = apple[min];
        apple[min] = tmp;
    }

    // 表示
    for (int i = 0; i < n; i++)
        printf("%d ", apple[i]);
    printf("\n");

    return 0;
}
