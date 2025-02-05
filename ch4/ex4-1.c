#include <stdio.h>

void teaspoon(int);

void teaspoon(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%dさじ", i);
        if (i < n)
            printf("、");
    }
    printf("\n");
    return;
}

int main(void) {
    int n;
    for (;;) {
        printf("何杯？");
        scanf("%d", &n);
        if (n == 0)
            break;
        teaspoon(n + 1);
        printf("お湯を注ぐ…\n");
        printf("お茶をどうぞ！\n");
    }
    printf("またどうぞ\n");
    return 0;
}
