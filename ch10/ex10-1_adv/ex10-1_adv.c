#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // srcがコピー元、dstがコピー先のファイル名
    char src[1024], dst[1024]; 
    FILE *ifp, *ofp; // コピー元ストリーム、コピー先ストリーム
    int c;  // fgetcの戻り値(EOF)

    printf("コピー元？");
    scanf("%s",src);
    // "-"が入力されたら標準入力を指す
    if (!strcmp(src, "-")) {
        ifp = stdin;
    } else { 
        if ((ifp = fopen(src, "r")) == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }
    }

    printf("コピー先？");
    scanf("%s", dst);
    // "-"が入力されたら標準出力を指す
    // TODO: 先頭の改行コードを削除する
    if (!strcmp(dst, "-")) {
        ofp = stdout;
    } else {
        if ((ofp = fopen(dst, "w")) == NULL) { // 書き込み
            perror("fopen");
            exit(EXIT_FAILURE);
        }
    }

    // 1文字ずつファイルをコピー
    // 入力ストリームから1文字ずつ読んで1文字ずつ出力ストリームに書く
    while ((c = fgetc(ifp)) != EOF) 
        fputc(c, ofp);
    
    fclose(ofp);
    fclose(ifp);
    return 0;
}