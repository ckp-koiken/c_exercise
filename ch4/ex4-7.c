#include <stdio.h>

#define SWAP(x, y, type) { type t = x; x = y; y = t; }

int main(void) {
    int i, j;
    double d, e;

    printf("整数を空白で区切って2つ入力してください ");
    scanf("%d %d", &i, &j);
    printf("入れ替えます\n");
    SWAP(i, j, int) // ブロックに展開されるのでセミコロンをつけない
    printf("i=%d, j=%d\n", i, j);

    printf("実数を空白で区切って2つ入力してください ");
    scanf("%lf %lf", &d, &e);
    printf("入れ替えます\n");
    SWAP(d, e, double)
    printf("d=%lf, e=%lf\n", d, e);

    return 0;
}
