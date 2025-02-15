#include <stdio.h>

void swap(int *a, int *b);
int gcd(int x, int y);

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int gcd(int x, int y) {
    if (x < y)
        swap(&x, &y);

    while (x >= 0) {
        x = x % y;
        if (x == 0)
            break;
        else
            swap(&x, &y);
    }
    return y;
}

int main(void) {
    int n, d, f;

    printf("分子？");
    scanf("%d", &n);
    printf("分母？");
    scanf("%d", &d);

    f = gcd(n, d);
    
    printf("約分すると %d/%d\n", n/f, d/f);
    return 0;
}
