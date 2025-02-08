#include <stdio.h>

int compound_i(int p, int y, int rp);

// TODO: int型のみで小数の利息の処理を追加
int compound_i(int p, int y, int rp) {
    for (int i = 0; i < y; i++)
        p *= (1+rp/100);
    return p;
}

int main(void) {
    int pv, year, rate, final;
    
    printf("最初の金額[円]？");
    scanf("%d", &pv);
    printf("複利の年利率[％]？");
    scanf("%d", &rate);
    printf("年数？");
    scanf("%d", &year);

    final = compound_i(pv, year, rate);

    printf("%d年後の金額は%d円です\n", year, final);
    return 0;
}
