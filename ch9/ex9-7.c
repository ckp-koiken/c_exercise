#include <stdio.h>

struct complex {
    double real, imag;  // realが実部、imagが虚部
};

struct complex add_complex(struct complex x, struct complex y);
struct complex mul_complex(struct complex x, struct complex y);

struct complex add_complex(struct complex x, struct complex y) {
    struct complex tmp; // 結果を入れる一時変数

    tmp.real = x.real + y.real;
    tmp.imag = x.imag + y.imag;
    return tmp; // tmpごと返す
}

struct complex mul_complex(struct complex x, struct complex y) {
    struct complex tmp;

    tmp.real = x.real * y.real - x.imag * y.imag;
    tmp.imag = x.real * y.imag + x.imag * y.real;
    return tmp;
}

int main(void) {
    struct complex x, y, sum, prod;

    printf("複素数x [a+bi]？");
    scanf("%lf%lfi", &x.real, &x.imag);
    printf("複素数y [a+bi]？");
    scanf("%lf%lfi", &y.real, &y.imag);

    sum = add_complex(x, y);
    prod = mul_complex(x, y);

    printf("和 %.1lf+%.1lfi\n", sum.real, sum.imag);
    printf("積 %.1lf+%.1lfi\n", prod.real, prod.imag);

    return 0;
}