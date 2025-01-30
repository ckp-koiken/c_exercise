#include <stdio.h>

int main(void) {
    int a, b, check;
    printf("aの値？");
    scanf("%d", &a);
    printf("bの値？");
    scanf("%d", &b);

    check += a!= b;
    check += a < b;
    check += (0 <= a && a <= 5);
    check += !(0 < b && b < 3);
    check += a != 0 ;

    printf("%d個の式が成立しています\n", check);

    return 0;
}
