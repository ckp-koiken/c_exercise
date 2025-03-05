#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calctax(int price);  // tax.cに記述されているcalctaxのプロトタイプ宣言

double rate;    // 消費税率の外部変数
int option;     // "-d"が指定されたかどうかを保持

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("消費税率を引数で指定してください\n");
        exit(EXIT_FAILURE);
    }

    // コマンドライン引数のオプション
    // 引数に-dが渡されたときの動作
    // TODO: オプションが第1引数に存在しないとエラーを起こすのを改善
    if (strcmp(argv[1], "-d") == 0)
        option = 1;

    int price, tax;
    rate = atof(argv[2]);
    printf("商品の価格？");
    scanf("%d", &price);
    tax = calctax(price);  // tax.cにあるcalctaxを呼び出す
    if (option == 1) {
        printf("calctax: price = %d, rate = %.2f, tax = %d\n", price, rate, tax);
        printf("消費税%d円、税込金額%d円\n", tax, tax+price);
    } else 
        printf("消費税%d円、税込金額%d円\n", tax, tax+price);
    return 0;
}