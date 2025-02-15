#include <stdio.h>

int main(void) {
    int i = 5; 
    int *p;

    p = &i;
    printf("i = %d, &i = %p, p = %p, *p = %d\n", i, (void *)&i, (void *)p, *p);
    *p = *p + 1;
    printf("i = %d, &i = %p, p = %p, *p = %d\n", i, (void *)&i, (void *)p, *p);
    return 0;
}
