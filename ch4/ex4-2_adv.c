#include <stdio.h>

int round_dir(double x, int method);

int round_dir(double x, int method) {
    double result;
    switch (method) {
        case -1:
            result = (int)x;
            break;
        case 0:
            result = (int)(x + 0.5);
            break;
        case 1:
            result = (int)x + 1;
            break;
    }
    return result;
}
int main(void) {
    int way, ans;
    double num;
    printf("数値？");
    scanf("%lf", &num);
    printf("種類（切り捨て-1、四捨五入0、切り上げ1）？");
    scanf("%d", &way);
    ans = round_dir(num, way);
    printf("%d\n", ans);
    return 0;
}
