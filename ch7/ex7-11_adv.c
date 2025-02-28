#include <stdio.h>
#include <stdlib.h>

char *mgets(void) {
    char *p, *newp;
    int c;
    size_t sz = 16;      // 現在の領域サイズを覚えておく変数

    if ((p = malloc(sz)) == NULL)   // 最初に16バイト確保
        return NULL;
    while ((c = getchar()) != EOF) {    // getcharで文字を受け付ける
        if (c == '\n')              // 改行文字で止める
            break;
        *p = c;
        p++;    // TODO: 要修正
        // if (*p == '\0') {
        //     if ((newp = realloc(p, sz+16)) == NULL)  
        //         break;
        //     p--;   
        //     p = newp;
        //     sz += 16;           
        //     p[sz-18] = c;
        // }
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