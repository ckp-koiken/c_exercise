#include <stdio.h>

void reverse(int *a, int n);

void reverse(int *a, int n) {
    int i, t;

    for (i = 0; i < n / 2; i++) {
        t = a[i];       // 真ん中を境に要素を入れ替える
        a[i] = a[n-i-1];
        a[n-i-1] = t;
    }
}

int main(void) {
    int a[] = {12, 3, 456, 7, 89, 100};
    int i;

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    reverse(a, sizeof(a)/sizeof(a[0]));

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
