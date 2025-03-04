#include <stdio.h>

double jpy_usd;             // 外部変数の定義宣言

int usd_to_jpy(double d);   // 関数のプロトタイプ宣言
double jpy_to_usd(int y);

int usd_to_jpy(double d) {  // 戻り値がintなので小数点以下切り捨て
    return jpy_usd * d;
}

double jpy_to_usd(int y) {
    return ((y / jpy_usd) * 100 - 0.5) / 100;  //1セント 以下切り捨て
}

int main(void) {
    double d;
    int choice, yen;

    printf("1ドルは何円？");
    scanf("%lf", &jpy_usd);

    for (;;) {
        printf("ドル->円[1], 円->ドル[2], 終了[0]？");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("何ドル？");
            scanf("%lf", &d);
            yen = usd_to_jpy(d);
            printf("%.2fドルは%d円になります\n", d, yen);
        } else if (choice == 2) {
            printf("何円？");
            scanf("%d", &yen);
            d = jpy_to_usd(yen);
            printf("%d円は%.2fドルになります\n", yen, d);
        } else if (choice == 0)
            break;
    }

    printf("良い旅を！\n");
    return 0;
}