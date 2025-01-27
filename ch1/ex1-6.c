#include <stdio.h>

int main(void) {
    int high, low, deg;
    printf("最低温度？");
    scanf("%d", &low);
    printf("最高温度？");
    scanf("%d", &high);

    // 数字表示
    deg = low;
    while (deg <= high) {
        printf("%3d ", deg); // 空白を加えて4文字幅で表示
        deg += 10;
    }
    printf("\n");

    // 線を表示
    deg = low;
    while (deg <= high) {
        printf("--+-"); // 数字に合わせて4文字
        deg += 10;
    }
    printf("\n");

    return 0;
}
