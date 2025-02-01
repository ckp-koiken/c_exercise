#include <stdio.h>

int main(void) {
    float num;
    printf("指数表現（3e-20など）で数値を入力してください: ");
    scanf("%e", &num); // 3e-24でアンダーフロー
    printf("2乗したら%eになりました\n", num * num);
    return 0;
}
