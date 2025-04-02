#include <stdio.h>

int yeast(int n);

int yeast(int n) {
    // ベースケース
    // 時間1のとき栄養素は1
    if (n == 1) 
        return 1;
   
    // 1時間経過すると酵母は2倍に分裂して
    // それぞれ栄養素を生成する
    return 1 + 2 * yeast(n - 1);
}

int main(void) {
    int n, count;
    printf("時間？");
    scanf("%d", &n);
    
    count = yeast(n);
    for (int i = 0; i < count; i++) {
        printf("*");
    }
    printf(" %d\n", count);
    return 0;
}