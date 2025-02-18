#include <stdio.h>

void reverse_s(int *a);

void reverse_s(int *a) {
    int i, t, count;

    i = 0;
    count = 0;
    while (a[i] != -1) {
        count++;        // 配列の要素数をcountで数える
        i++;
    }
    printf("i = %d, count = %d\n", i, count);

    for (i = 0; i < count/2; i++) {
        t = a[i];
        a[i] = a[count-i-1];
        a[count-i-1] = t;
    }
}

int main(void) {
    int a[] = {12, 3, 456, 7, 89, 100, -1};
    int i;

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    reverse_s(a);

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
