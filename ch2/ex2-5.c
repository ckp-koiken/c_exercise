#include <stdio.h>

int main(void) {
    double d, x;
    int n;
    printf("床一辺の長さ[m]？");
    scanf("%lf", &x);

    printf("人数？");
    scanf("%d", &n);
    
    d = n / (x * x);

    printf("人口密度は%.3lf人/平方メートルです\n", d);

    return 0;
}
