#include <stdio.h>

void concat(char *p, char *q);
void vconcat(char *p, char *q[]);

void concat(char *p, char *q) {
    if (*p) {           // pが空文字列でないなら
        while (*p)      // pの末尾を探して下線を追加
            p++;
        *p++ = '_';     // *p = '_';
    }                    // p++;
    while (*q)          // qの文字を一文字ずつpに追加する
        *p++ = *q++;
    *p = '\0';          // 空文字で終える
}

// q[]の内容をconcatする関数
void vconcat(char *p, char *q[]) {
    while (*++q) {
        concat(p, *q);
    }
}

// MEMO: string.hをインクルードして以下のようにすると
// 汎用性が上がる（コマンドライン引数以外の時でも使いやすい）
// #include <string.h>
// void vconcat(char *p, char *q[]) {
//     while (*q) {
//         if (!strcmp(*q, "./a.out"))
//             q++;
//         concat(p, *q);
//         q++;
//     }
// }

int main(int argc, char *argv[]) {
    char s[1024] = "";

    vconcat(s, argv);

    printf("%s\n", s);
    return 0;
}