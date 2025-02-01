#include <stdio.h>

int main(void) {
    int n, score;
    double total;
    printf("科目数? ");
    scanf("%d", &n);
    total = 0;
    for (int i = i; i <= n; i++) {
        printf("科目%dの点数? ", i);
        scanf("%d", &score);
        total += score;
    }
    printf("平均%.1lf点\n", total / n);
    return 0;
}
