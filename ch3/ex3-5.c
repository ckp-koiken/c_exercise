#include <stdio.h>

int main(void) {
    printf("     | 1| 2| 3| 4| 5| 6| 7| 8| 9|\n"); // 1行目
    printf("-----+--+--+--+--+--+--+--+--+--+\n"); // 2行目
    for (int i = 1; i <= 9; i++) {
        printf("%dの段|", i);
        /* iの段を表示する */
        for (int j = 1; j <= 9; j++) {
            printf("%2d|", i * j);
        }
        printf("\n");
    }


    return 0;
}
