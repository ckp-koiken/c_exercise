#include <stdio.h>
#include <math.h>

#define STUDENT 100

int main(void) {
    int n, point, n_list[STUDENT];
    double total, ave, point_sq, stdv, ss;
    
    n = 0;
    printf("点数を入力してください（終了は-1）終了\n");
    while (n < STUDENT) {
        printf("点数？");
        scanf("%d", &point);

        if (point == -1)
            break;
        n_list[n] = point;
        n++;
    }
    
    // 平均と標準偏差を求める
    total = 0;
    for (int i = 0; i < n; i++) {
        total += n_list[i]; // 点数の合計
        point_sq += n_list[i] * n_list[i]; // 点数の2乗総和
    }
    ave = total / n; // 平均
    stdv = sqrt(point_sq / n - ave * ave); // 標準偏差

    printf("平均点%.1lf、標準偏差%.1lf点\n", ave, stdv);

    // 各点数の偏差値を求めて表示する
    for (int i = 0; i < n; i++) {
        ss = 10 * (n_list[i] - ave)/stdv + 50; // 偏差値
        printf("%d点、偏差値%.1lf\n", n_list[i], ss); 
    }

    return 0;
}
