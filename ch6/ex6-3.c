#include <stdio.h>

int main(void) {
    int a[5] = {100, 101, 102, 103, 104};
    double b[5] = {1.0, 1.1, 1.2, 1.3, 1.4};

    printf("sizeof(a) = %zu, sizeof(a[0]) = %zu\n", sizeof(a), sizeof(a[0]));
    printf("sizeof(a)/sizeof(a[0]) = %zu\n", sizeof(a)/sizeof(a[0]));
    printf("a[0] = %d, &a[0] = %p, a = %p, *a = %d\n",
            a[0], (void *)a, (void *)&a[0], *a);
    printf("a[1] = %d, &a[1] = %p, a+1 = %p, *(a+1) = %d\n",
            a[1], (void *)&a[1], (void *)(a+1), *(a+1));
    printf("a[2] = %d, a[2] = %p, a+2 = %p, *(a+2) = %d\n",
            a[2], (void *)&a[2], (void *)(a+2), *(a+2));

    printf("sizeof(b) = %zu, sizeof(b[0]) = %zu\n", sizeof(b), sizeof(b[0]));
    printf("sizeof(b)/sizeof(b[0]) = %zu\n", sizeof(b)/sizeof(b[0]));
    printf("b[0] = %f, &b[0] = %p, b = %p, *b = %f\n",
            b[0], (void *)b, (void *)&b[0], *b);
    printf("b[1] = %f, &b[1] = %p, b+1 = %p, *(b+1) = %f\n",
            b[1], (void *)&b[1], (void *)(b+1), *(b+1));
    printf("b[2] = %f, &b[2] = %p, b+2 = %p, *(b+2) = %f\n",
            b[2], (void *)&b[2], (void *)(b+2), *(b+2));
    return 0;
}
