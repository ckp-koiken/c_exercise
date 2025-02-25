#include <stdio.h>

int main(void) {
    int c, pc;
    char s[1024], *p;

    printf("コンマ区切りの行を入力して下さい：");
    fgets(s, sizeof(s), stdin);

    for (p = s; *p != '\0'; p++) {
        if (*p == ',') {
            *p = '\n';
        }
    }

    printf("%s", s);

    // TODO: コンマを空文字で置き換えてフィールド番号ごとに表示したい
    return 0;
}