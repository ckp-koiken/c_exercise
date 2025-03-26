#include <stdio.h>

#define EPSILON 0.00001
int main(void) {
    double a, x;

    printf("ルートいくつ？");
    scanf("%lf", &a);
    x = a;

    while (x*x-a < -EPSILON || EPSILON < x*x-a) // |x*x-1| > EPSILONである間
        x = (x + a / x) / 2;
    
    printf("%.10fの2乗は%.10f\n", x, x*x);
    return 0;
}