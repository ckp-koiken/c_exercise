#include <stdio.h>

int main(void) {
    double x, y, ans;
    int choice;
    printf("x? ");
    scanf("%lf", &x);
    printf("y? ");
    scanf("%lf", &y);
    printf("演算を選んでください 1: 加算、2: 減算、3: 乗算、4: 除算? ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            ans = x + y;
            break;
        case 2:
            ans = x - y;
            break;
        case 3:
            ans = x * y;
            break;
        case 4:
            ans = x / y;
            break;
        default:
            printf("演算の指定が間違っています\n");
            return 0;
    }

    printf("答え %lf\n", ans);
    return 0;
}
