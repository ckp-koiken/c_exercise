#include <stdio.h>

int main(void) {
    int a, b;
    a = 3; b = 2;

    printf("a = %d, b = %d\n", a, b);
    printf("a > b -> %d\n", a > b);
    printf("a == b -> %d\n", a == b);
    printf("0 < a < 2 -> %d\n", 0 < a <2); // (0<a)が1で1<2なので式全体が1
    printf("0 < a && a < 2 -> %d\n", 0 < a && a < 2);
    printf("a < 4 || 6 < a -> %d\n", a < 4 || 6 < a);
    printf("!a -> %d\n", !a); // a=3が真で、その否定なので偽
    return 0;
}
