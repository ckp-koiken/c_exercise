#include <stdio.h>

struct rational {
    int np, dp;
};

struct rational cancel(struct rational ratio);

struct rational cancel(struct rational ratio) {
    int fact = 2;

    while (fact <= ratio.dp) {
        if (ratio.np % fact == 0 && ratio.dp % fact == 0) {
            ratio.np /= fact;
            ratio.dp /= fact;
        } else 
            fact++;
    }
    return ratio;
}

int main(void) {
    struct rational x, y;
    printf("分子？");
    scanf("%d", &x.np);
    printf("分母？");
    scanf("%d", &x.dp);

    y = cancel(x);

    printf("約分すると %d/%d\n", y.np, y.dp);

    return 0;
}