#include <stdio.h>

int main(void) {
    int high, low, now, deg, scale;
    printf("最低温度？");
    scanf("%d", &low);
    printf("最高温度？");
    scanf("%d", &high);
    printf("現在の温度？");
    scanf("%d", &now);

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

    // 目盛を表示
    deg = low;
    while (deg <= now+5) {
        printf("##");
        deg += 5;
    }
    printf("\n");

    return 0;
}
