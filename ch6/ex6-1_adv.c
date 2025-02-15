#include <stdio.h>

int main(void) {
    int i = 10;
    int *p;
    void *v;

    v = &i;
    printf("v = %p\n", v);

    p = v;
    printf("p = %p\n", (void *)p);

    *p = *p + 1;
    printf("i = %d\n", i);

    return 0;
}
