#include <stdio.h>

double power (double x, int n); 

int compound (int p, int y, double r);

// math.hをincludeしてpow()関数を使うこともできる
double power (double x, int n) {
    double y = 1.0;
    for (int i = 0; i < n; i++)
        y *= x;
    return y;
}

int compound (int p, int y, double r) {
    return p * power(1+r, y);
}

int main(void) {
    int pv, year, last;
    double rate;
    
    printf("最初の金額[円]？");
    scanf("%d", &pv);
    printf("複利の年利率[％]？");
    scanf("%lf", &rate);
    printf("年数？");
    scanf("%d", &year);

    last = compound(pv, year, rate/100);

    printf("%d年後の金額は%d円です\n", year, last);

    return 0;
}
