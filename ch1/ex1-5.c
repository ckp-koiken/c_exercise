#include <stdio.h>

int main(void) {
    int num;
    printf("整数?: ");
    scanf("%d", &num);
    if (num > 0)
        printf("%dは正です\n", num);
    else if (num < 0)
        printf("%dは負で、絶対値は%dです\n", num, -num);
    else
        printf("ゼロです\n");
    return 0;
}
