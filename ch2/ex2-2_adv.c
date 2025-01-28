#include <stdio.h>

int main(void) {
    int price, cost;
    double profit_rate;
    printf("原価は？");
    scanf("%d", &cost);
    printf("価格は？");
    scanf("%d", &price);
    profit_rate = ((price*1.0 - cost) / price*1.0) * 100;
    printf("利益率は%.1lf%%です\n", profit_rate);
    return 0;
}
