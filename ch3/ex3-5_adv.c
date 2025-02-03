#include <stdio.h>

// TODO: y=x^3にも対応させる。表示範囲の問題をクリアする。
int main(void) {
    for (int x = -10; x <= 10; x++) {
        for (int y = -20; y <= 30; y++) {
            if (y == x*x/4)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
