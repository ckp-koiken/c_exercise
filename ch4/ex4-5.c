#include <stdio.h>
#include <unistd.h>

int is_fizz(int n);

// 3がつくか3の倍数かを判定する
int is_fizz(int n) {
    if (n % 3 == 0)
        return 1;
    while (n > 0) {
        if (n % 10 == 3)
            return 1;
        n /= 10;
    }
    return 0;
}

int main(void) {
    int n;
    printf("いくつまで？");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sleep(1);
        if (is_fizz(i)) {
            if (i % 5 == 0)
                printf("Fizz Buzz\n");
            else 
                printf("Fizz\n");
        } else if (i % 5 == 0)
            printf("Buzz\n");
        else
            printf("%d\n", i);
    }
    return 0;
}
