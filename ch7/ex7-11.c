#include <stdio.h>
#include <stdlib.h>

char *mgets(void) {
    char *p, *newp;
    int c;
    size_t sz = 1;      // 現在の領域サイズを覚えておく変数

    if ((p = malloc(sz)) == NULL)   // まず1文字分確保
        return NULL;
    while ((c = getchar()) != EOF) {    // getcharで文字を受け付ける
        if (c == '\n')              // 改行文字で止める
            break;
        if ((newp = realloc(p, sz+1)) == NULL)  // reallocでnewpに1文字分追加
            break;      // 拡張した領域の先頭アドレスが以前とは同じとは限らない
        p = newp;       // バグ対策でいったんnewpに渡す
        sz++;           // 確保サイズを１つ大きくする
        p[sz-2] = c;    // 1番後ろの一つまえに文字を入れる
    }
    p[sz-1] = '\0';     // 1番後ろに空文字を入れる
    return p;
}

int main(void) {
    char *vnam, *fnam;

    printf("ファーストネーム？");
    vnam = mgets();
    printf("ファミリーネーム？");
    fnam = mgets();
    printf("ようこそ、%s %sさん！\n", vnam, fnam);
    free(vnam);
    free(fnam);
    return 0;
}