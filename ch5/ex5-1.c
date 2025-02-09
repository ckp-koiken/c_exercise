#include <stdio.h>

int main(void) {
    int a[10];

    printf("登ります！\n");
    for (int i = 0; i < 10; i++) {
        if (i < 9)
            printf("%d合目の標高？", i+1);
        else
            printf("山頂の標高？");
        scanf("%d", &a[i]);
    }

    printf("下ります\n");
    for (int i = 9; i >= 0; i--) {
        if (i == 9)
            printf("山頂：%d m\n", a[i]);
        else
            printf("%d合目：%d m\n", i, a[i]);
    }
    printf("無事下山しました！\n");

    return 0;
}
