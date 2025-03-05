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

    // -dがオプションで渡されていたらフラグをたてる
    if (!strcmp(argv[1], "-d"))  
        option = 1;

    int price, tax;
    printf("商品の価格？");
    scanf("%d", &price);

    // コマンドライン引数のオプション
    if (option == 1) {
        rate = atof(argv[2]);   // -dが渡されたらrateに第2引数を
        tax = calctax(price); 
        printf("calctax: price = %d, rate = %.2f, tax = %d\n", price, rate, tax);
        printf("消費税%d円、税込金額%d円\n", tax, tax+price);
    } else {
        rate = atof(argv[1]);   // オプションがなければrateに第1引数を
        tax = calctax(price); 
        printf("消費税%d円、税込金額%d円\n", tax, tax+price);
    }

    // MEMO: unistd.hのgetopt関数を使えば色んなオプションに対応できる
    return 0;
}