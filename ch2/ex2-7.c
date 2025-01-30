#include <stdio.h>

int main(void) {
    double i, j;
    printf("値？");
    scanf("%lf", &i);
    j = (int)(i*100) / 100.0; // intへのキャスト
    printf("%lf\n", j);

    return 0;
}
