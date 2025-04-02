#include <stdio.h>
#include <time.h>

#define N 15

int fib(int n);
int fib_loop(int n);

int fib(int n) {
    if (n < 2)
        return n;
    else
        return fib(n - 2) + fib(n - 1);
}

int fib_loop(int n) {
    int fn, fn1, fn2;

    if (n < 2)
        return n;
    else {
        fn2 = 0;
        fn1 = 1;
        for (int i = 1; i < n; i++) {
            fn = fn2 + fn1;
            fn2 = fn1;
            fn1 = fn;
        }
        return fn;
    }
}

int main(void) {
    clock_t start_time, finish_time;
    start_time = clock();

    // fib(N);  // 0.000005秒かかった
    fib_loop(N);  // 0.000001秒かかった
    // 再帰よりループの方が少し早い

    finish_time = clock();
    printf("%f秒かかった\n", (double)(finish_time - start_time) / CLOCKS_PER_SEC);
    return 0;
}