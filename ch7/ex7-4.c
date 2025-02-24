#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c, pc;

    pc = '\n';      // pc: 1つ前の文字、最初の文字を行頭扱いにする
    while ((c = getchar()) != EOF) {
        if (pc == '\n')
            putchar(toupper(c));
        else 
            putchar(c);
        pc = c;     // いま出力した文字を覚えておく
    }
    printf("\n");
    return 0;
}