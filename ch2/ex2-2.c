#include <stdio.h>

int main(void) {
    int price, tax, pay, point;
    printf("商品代金（税抜き）？");
    scanf("%d", &price);
    tax = price * 0.08;
    pay = price + tax;
    point = pay * 0.1;

    printf("消費税%d円、お支払い額%d円です\n", tax, pay);
    printf("%dポイントつきました！\n", point);

    return 0;
}
