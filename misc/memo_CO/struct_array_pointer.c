#include <stdio.h>

int main(void) {
    struct DATA { short x, y; };
    struct DATA d[5] = { 0, 1, 2, 3 };
    int num = sizeof(d) / sizeof(d[0]);

    struct DATA* p = d;
    for (int i = 0; i < num; i++) {
        p[i].x = i + 1;
        p[i].y = i + 2;
    }

    for (int i = 0; i < num; i++) {
        (p + i)->x = i + 1;
        (p + i)->y = i + 2;
    }

    for (int i = 0; i < num; i++) {
        p->x = i + 1;
        p->y = i + 2;
        p++;
    }

    for (int i = 0; i < num; i++) {
        printf("%d %d\n", d[i].x, d[i].y);
    }

    return 0;
}
