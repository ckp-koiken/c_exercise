#include <stdio.h>

void concat(char *p, char *q);

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

int main(int argc, char *argv[]) {
    char s[1024] = "";

    while (*++argv)     // argv[1]から順にsに追加(++argv && *argv)
        concat(s, *argv);
    printf("%s\n", s);
    return 0;
}