#include <stdio.h>

int main(void) {
    int income, check;
    int cash[] = {1950, 3300, 6950, 9000, 18000, 40000, 40001};
    double rate[] = {0.05, 0.1, 0.2, 0.23, 0.33, 0.4, 0.45};

    printf("所得[千円]？");
    scanf("%d", &income);

    // TODO: 配列の探索をスマートにする？
    check = 0;
    for (int i = 0; i < sizeof(cash)/sizeof(cash[0]); i++) {
        if (income > cash[i] && income <= cash[6])
            check += 1;
        else if (income > cash[6]) {
            check = 6;
            break;
        }
    }

    printf("%d千円に対する所得税率は%.1lf%%です\n", income, rate[check]*100);

    return 0;

}
