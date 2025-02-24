#include <stdio.h>
#include <ctype.h>

int kind(unsigned char c);

int kind(unsigned char c) {
    if (islower(c))
        return 0;           // 小文字
    else if (isupper(c))
        return 1;           // 大文字
    else if (isdigit(c))
        return 2;           // 数字
    else if (isspace(c))
        return 3;           // 空白類文字
    else 
        return 4;           // その他
}

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        switch(kind(c)) {
            case 0: putchar('x'); break;
            case 1: putchar('X'); break;
            case 2: putchar('O'); break;
            case 3: putchar('_'); break;
            case 4: putchar('.'); break;
        }
        if (c == '\n')      // cが改行文字なら、
            putchar('\n');  // さらに改行文字を出力
    }
    return 0;
}