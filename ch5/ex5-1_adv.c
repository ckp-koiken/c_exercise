#include <stdio.h>

int main(void) {
    int a[10];
    int i, j;

    printf("登ります！\n");
    for (i = 0; i < 10; i++) {
        if (i < 9)
            printf("%d合目の標高？", i+1);
        else
            printf("山頂の標高？");
        scanf("%d", &a[i]);

        if (a[i] == 0)
            break;
    }

    printf("下ります\n");
    for (j = i-1; j >= 0; j--) {
        if (i == 9)
            printf("山頂：%d m\n", a[j]);
        else
            printf("%d合目：%d m\n", j, a[j]);
    }
    printf("無事下山しました！\n");

    return 0;
}
