#include <stdio.h>

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
    int n;
    printf("時間？");
    scanf("%d", &n);
    
    printf("%d", yeast(n));
    printf("\n");
    return 0;
}