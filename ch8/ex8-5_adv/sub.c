#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myheader.h"

// 静的変数の定義宣言
// sub.c内でしか以下の変数を使わないようにする
static int nbooks; // 入力された本の冊数
static char *books[MAXBOOKS]; // 題名を保持する文字列ベクタ
static int prices[MAXBOOKS];  // 値段を保持する配列


// 1行を読み込む共通の処理
static void get_line(char *p, int size) {
    fgets(p, size, stdin);
    while (*p == '\n')  // 改行だけの行は捨てる
        fgets(p, size, stdin);
    while (*p) {
        if (*p == '\n') {  // 改行文字があれば
            *p = '\0';     // 空文字で上書きして取り除く
            break;
        }
        p++;
    }
}

// 本の情報を外部変数に読み込む
void read_books(void) {
    char *p;

    nbooks = 0;
    for (;;) {
        // 題名の領域を確保
        if ((p = malloc(TITLESIZE)) == NULL) {
            perror("malloc");
            break;
        }
        printf("#%d 題名: ", nbooks);
        get_line(p, TITLESIZE); // 題名読み取り
        // 入力が.だけなら確保した領域を解放して読み込み終了
        if (p[0] == '.' && p[1] == '\0') {
            free(p);
            break;
        }
        books[nbooks] = p; // 題名を入れた文字列を配列に追加
        printf("#%d 値段: ", nbooks);
        scanf("%d", &prices[nbooks]);  // 値段読み込み
        nbooks++;
    }

    // 読み込んだ一覧を表示
    for (int i = 0; i < nbooks; i++)
    printf(" 「%s」 %d円\n", books[i], prices[i]);
}

void search_books(void) {
    char buf[TITLESIZE];
    int i;

    for (;;) {
        printf("探す本？");
        get_line(buf, TITLESIZE);  // 探す本の題名をキーボードから読み込む
        if (buf[0] == '.' && buf[1] == '\0')
            // 入力が.なら戻る
            return;
        for (i = 0; i < nbooks; i++) {
            // 題名が見つかったらbreak
            if (strcmp(buf, books[i]) == 0)
                break;
        }
        if (i < nbooks) // ループ条件が成り立っているならbreakしてきている
            printf("見つかりました。「%s」 %d円です\n", books[i], prices[i]);
        else  // ループを回り切っても見つからない
            printf("見つかりません...\n");
    }
}