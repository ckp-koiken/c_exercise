#include <stdio.h>

double jpy_usd;             // 外部変数の定義宣言

int usd_to_jpy(double d);   // 関数のプロトタイプ宣言

int usd_to_jpy(double d) {  // 戻り値がintなので小数点以下切り捨て
    return jpy_usd * d;
}

int main(void) {
    double d;
    int y;

    printf("1ドルは何円？");
    scanf("%lf", &jpy_usd);
    printf("何ドル？");
    scanf("%lf", &d);
    y = usd_to_jpy(d);
    printf("%.2fドルは%d円になります\n", d, y);
    return 0;
}