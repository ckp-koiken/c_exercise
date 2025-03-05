#include <stdio.h>
#include <stdlib.h>

int calctax(int price);  // tax.cに記述されているcalctaxのプロトタイプ宣言

double rate;    // 消費税率の外部変数

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("消費税率を引数で指定してください\n");
        exit(EXIT_FAILURE);
    }

    int price, tax;
    rate = atof(argv[1]);
    printf("商品の価格？");
    scanf("%d", &price);
    tax = calctax(price);  // tax.cにあるcalctaxを呼び出す
    printf("消費税%d円、税込金額%d円\n", tax, tax+price);
    return 0;
}