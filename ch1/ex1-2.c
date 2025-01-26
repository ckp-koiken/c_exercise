#include <stdio.h>

int main(void) {
    int y1, y2, m1, m2, d1, d2, prec1, prec2;
    double high1, high2, low1, low2;

    y1 = 2020; m1 = 2; d1 = 4; prec1 = 0; high1 = 9.59; low1 = -10.1;
    y2 = 2020; m2 = 10; d2 = 20; prec2 = 30; high2 = 15.3; low2 = 5.51; 

    printf("最高 %f, 最低 %f\n", high2, low1);
    printf("%4d/%02d/%02d   %10f %10f  %2d%%\n", y1, m1, d1, high1, low1, prec1);
    printf("%4d/%02d/%02d   %10f %10f  %2d%%\n", y2, m2, d2, high2, low2, prec2);
    return 0;
}
