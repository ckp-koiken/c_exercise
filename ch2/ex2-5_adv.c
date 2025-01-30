#include <stdio.h>

int main(void) { 
    int n, m, p, last;
    printf("1列の座席数？ ");
    scanf("%d", &n);
    printf("一部屋にある列の数？ ");
    scanf("%d", &m);
    printf("受験者数？ ");
    scanf("%d", &p);

    last = p % (n * m);
    printf("最後の一部屋は%d人です\n", last);

    return 0;
}
