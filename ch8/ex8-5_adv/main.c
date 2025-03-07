#include <stdio.h>
#include "myheader.h"

int main(void) {
    read_books();   // 本の情報を読み込む

    search_books(); // 本の検索モードへ

    printf("お疲れ様でした!\n");
    return 0;
}