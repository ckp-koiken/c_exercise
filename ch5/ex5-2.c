#include <stdio.h>

int main(void) {
    int nday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year;
    printf("西暦何年？");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        nday[1] = 29;

    for (int i = 0; i < 12; i++) {
        printf("%2d月%d日 ", i+1, nday[i]);
        if (i % 4 == 3)
            printf("\n");
    }

    return 0;
}
