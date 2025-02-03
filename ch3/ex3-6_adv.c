#include <stdio.h>

int main(void) {
    int num, check;
    printf("いくつまでの素数を表示する？");
    scanf("%d", &num);
    for (int i = 2; i <= num; i++) {
        check = 0;
        for (int j = 2; j <= i-1; j++) {
            if (i % j == 0)
                check += 1;
        }
        if (check == 0)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
