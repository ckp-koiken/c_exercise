#include <stdio.h>

int main(void) {
    double x, y, ans;
    char choice;
    printf("演算を選んでください +: 加算、-: 減算、*: 乗算、/: 除算? ");
    scanf("%s", &choice);
    printf("x? ");
    scanf("%lf", &x);
    printf("y? ");
    scanf("%lf", &y);

    switch (choice) {
        case 43: // ascii decimal '+'
            ans = x + y;
            break;
        case 45: // ascii decimal '-'
            ans = x - y;
            break;
        case 42: // ascii decimal '*'
            ans = x * y;
            break;
        case 47: // ascii decimal '/'
            ans = x / y;
            break;
        default:
            printf("演算の指定が間違っています\n");
            return 0;
    }

    printf("答え %lf\n", ans);
    return 0;
}
