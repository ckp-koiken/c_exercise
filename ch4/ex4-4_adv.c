#include <stdio.h>

double compound_i(int p, int y, double rp);

// TODO: int型のみでの処理に修正
double compound_i(int p, int y, double rp) {
    for (int i = 0; i < y; i++)
        p *= (1+rp/100);
    return p;
}

int main(void) {
    int pv, year;
    double rate, final;
    
    printf("最初の金額[円]？");
    scanf("%d", &pv);
    printf("複利の年利率[％]？");
    scanf("%lf", &rate);
    printf("年数？");
    scanf("%d", &year);

    final = compound_i(pv, year, rate);

    printf("%d年後の金額は%f円です\n", year, final);
    return 0;
}
