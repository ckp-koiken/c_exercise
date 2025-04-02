#include <stdio.h>

int fib(int n);

int fib(int n) {
    if (n < 2)
        return n;
    else
        return fib(n - 2) + fib(n - 1);
}

int main(void) {
    int n, x;

    printf("何番目？");
    scanf("%d", &n);
    x = fib(n);
    printf("%d番目のフィボナッチ数は%dです\n", n, x);
    return 0;
}