#include <stdio.h>
#include <stdlib.h>

char *mgets(void) {
    char *p, *newp;
    int c, index;
    size_t sz = 17;      // 現在の領域サイズを覚えておく変数

    if ((p = malloc(sz)) == NULL)   // 最初に16バイト確保
        return NULL;
    index = 0;  // 添字を数えるための変数
    while ((c = getchar()) != EOF) {    // getcharで文字を受け付ける
        if (c == '\n')              // 改行文字で止める
            break;
        *(p+index) = c;
        index++;
        if (index % 16 == 0) {      // indexが16の倍数に達したら再度確保
            if ((newp = realloc(p, sz+16)) == NULL)
                break;
            p = newp;
        }
        *(p+index) = '\0';    // 最後に入れた文字の次に空白文字を入れる
    }
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