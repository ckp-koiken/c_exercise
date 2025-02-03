#include <stdio.h>

// while文でも同じことができる
int main(void) {
    int sum;
    for (int i = 1; i <= 10000; i++) { // 1から10000まで調べる
        sum = 0;
        for (int j = 1; j <= i-1; j++) { // 約数を調べる
            if (i % j == 0)
                sum += j; // もし約数ならsumに足し込む
        }
        if (sum == i) // 約数合計とその数が一致しているならば完全数と判断する
            printf("%dは完全数\n", i);
    }
    return 0;
}
