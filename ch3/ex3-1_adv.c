#include <stdio.h>

int main(void) {
    int x, y, total;
    printf("xのy乗を求めます\n");
    printf("x? ");
    scanf("%d", &x);
    printf("y? ");
    scanf("%d", &y);
    total = 1;
    for (int i = 0; i < y; i++)
        total *= x;
    printf("%dの%d乗は%dです\n", x, y, total);

    return 0;
}
