#include <stdio.h>

int main(void) {
    int month, start, days;
    printf("何月？");
    scanf("%d", &month);
    switch (month) {
        case 2:
            days = 28;
            break;
        case 4:
            days = 30;
            break;
        case 6:
            days = 30;
            break;
        case 9:
            days = 30;
            break;
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }

    printf("ついたちは何曜日（日曜=0、土曜=6）？");
    scanf("%d", &start);
    printf("         %2d月         \n", month);
    printf(" 日 月 火 水 木 金 土 \n");
    printf("+--+--+--+--+--+--+--+\n");

    for (int j = 0; j < start; j++)
        printf("|  ");

    for (int i = 1; i <= days; i++) {
        printf("|%2d", i);
        if ((start + i) % 7 == 0) {
            printf("|\n");
            printf("+--+--+--+--+--+--+--+\n");
        }
    }

    // TODO: 最終週のマス目を表示する
    // for (int k = 0; k < 6-start; k++)
    //     printf("|  ");

    // printf("\n");
    // printf("+--+--+--+--+--+--+--+\n");

    printf("\n");
    return 0;
}
