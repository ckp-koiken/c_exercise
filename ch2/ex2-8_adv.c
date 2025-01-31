#include <stdio.h>

int main(void) {
    int n, r, total, deno, combi;
    printf("カードは全部で何枚？");
    scanf("%d", &n);
    printf("引く枚数？");
    scanf("%d", &r);

    // 順列計算
    total = 1;
    for (int i = 0; i < r; i++) {
        total *= n;
        n--;
    }

    // 分母計算
    deno = 1;
    while (r > 0) {
        deno *= r;
        r--;
    }

    // 組み合わせ計算
    combi = total / deno;

    printf("組み合わせは%d通りあります\n", combi);
    return 0;
}

    // 別解
    // total = 1;
    // deno = 1;
    // while (r > 0) {
    //     total *= n;
    //     deno *= r;
    //     n--;
    //     r--;
    // }
