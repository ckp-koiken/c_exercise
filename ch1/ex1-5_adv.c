#include <stdio.h>

int main(void) {
    int num;
    printf("テストの点数?: ");
    scanf("%d", &num);

    if (num>=90 && num<=100)
        printf("評価はSです!\n");
    else if (num >= 80)
        printf("評価はAです!\n");
    else if (num >= 70)
        printf("評価はBです!\n");
    else if (num >= 60)
        printf("評価はCです!\n");
    else
        printf("評価はFです...\n");

    return 0;
}
