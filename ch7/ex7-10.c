#include <stdio.h>

void to_binary(unsigned int n, char *bufp) {
    char *p = bufp, c;

    while (n > 0) {                 // nのビットを下から見ていく
        *p++ = n & 1 ? '1' : '0';   // 最下位ビットに応じて'1'か'0'をpに追加
        n >>= 1;                    // 右シフトして最下位ビットを捨てる
    }
    *p-- = '\0';                    // 空文字で終端し、pに末尾の文字を指させる

    // 逆順でbufpに2進数表現が求まっているので反転する
    while (bufp < p) {
        c = *bufp; *bufp++ = *p; *p-- = c;
    }
}

int main(void) {
    unsigned int val;
    char buf[1024];

    printf("非負整数を入力してください：");
    scanf("%u", &val);
    to_binary(val, buf);    // valを2進表記にしてbufに入れてもらう
    printf("2進表記で %s です\n", buf);
    return 0;
}