#include <stdio.h>

double round_to(double x, int n);

double round_to(double x, int n) {
    double mul, result;
    mul = 1;

    for (int i = 0; i < n; i++) {
        mul *= 10;
    }

    result = (int)(x * mul + 0.5) / mul;
    return result;
}

int main(void) {
    int rank;
    double num, ans;
    printf("数値？");
    scanf("%lf", &num);
    printf("小数点以下の桁数？");
    scanf("%d", &rank);

    ans = round_to(num, rank);

    printf("%lf\n", ans);
    
    return 0;
}
