#include <stdio.h>

int main(void) {
    int n, score, count, eval, dev;
    double credits;
    printf("科目数? ");
    scanf("%d", &n);
    
    credits = 0;
    dev = 0;
    for (int i = 1; i <= n; i++) {
        // 分子計算
        printf("科目%dの点数? ", i);
        scanf("%d", &score);
        printf("科目%dの単位数? ", i);
        scanf("%d", &count);
        if (score >= 90)
            eval = 4;
        else if (score >= 80)
            eval = 3;
        else if (score >= 70)
            eval = 2;
        else if (score >= 60)
            eval = 1;
        else 
            eval = 0;

        credits += eval * count;

        // 分母計算
        dev += count;
    }

    // GPA計算
    printf("GPA %.3lf\n", credits / dev);

    return 0;
}
