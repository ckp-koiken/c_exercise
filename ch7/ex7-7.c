#include <stdio.h>

int main(void) {
    char s[1024], *p, *q;

    printf("文字列？");
    fgets(s, sizeof(s), stdin);
    // 改行文字があれば取り除く
    for (p = s; *p != '\0'; p++) {
        if (*p == '\n') {
            *p = '\0';      // 改行文字を空文字で上書き
            break;
        }
    }

    if (s[0] == '\0') {
        printf("空文字列です\n");
    } else {
        // 文字列末尾の空文字を探す
        q = s;
        while (*q != '\0')
            q++;
        // 先頭と末尾から見ていく
        q--;    // qに末尾を指させる
        p = s;  // pに先頭を指させる
        while (p < q) {
            if (*p != *q)
                break;
            p++;
            q--;
        }
        if (p < q)  // ループ条件を満たしてるならbreakしているので回文ではない
            printf("「%s」は回文ではありません\n", s);
        else        // ループが回り切ったなら回文
            printf("「%s」は回文です\n", s);
    }
    return 0;
}