#include <stdio.h>
#include "myheader.h"

// 外部変数の定義宣言
int nbooks; // 入力された本の冊数
char *books[MAXBOOKS]; // 題名を保持する文字列ベクタ
int prices[MAXBOOKS];  // 値段を保持する配列

int main(void) {
    read_books();   // 本の情報を外部変数に読み込む

    // 一覧を表示
    for (int i = 0; i < nbooks; i++)
        printf(" 「%s」 %d円\n", books[i], prices[i]);

    // 本の検索モードへ
    search_books();
    printf("お疲れ様でした!\n");
    return 0;
}