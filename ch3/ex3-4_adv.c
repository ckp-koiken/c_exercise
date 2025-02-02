#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    unsigned int seed;
    double check;
    int n;
    srand(time(0));
    n = 0;

    for (int i = 0; i < 10000; i++) {
        double x, y;
        
        // xとyを発生
        x = (double)rand() / RAND_MAX; // 0~1の乱数を最大値で割った時の商。0以上1以下。
        y = (double)rand() / RAND_MAX; // 0より大きくしたいなら1.0を足す
        
        if (x * x + y * y <= 1)
            n += 1;
    }

    check = 4.0 * n / 10000;

    printf("内側%d回、%lf\n", n, check);
    
    return 0;
}
