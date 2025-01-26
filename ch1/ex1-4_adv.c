#include <stdio.h>

int main(void) {
    double bmi, weight, height;
    /* 入力 */
    printf("身長[cm]? ");
    scanf("%lf", &height);
    printf("体重[kg]? ");
    scanf("%lf", &weight);

    /* 計算 */ 
    height = height/100;
    bmi = weight / (height * height);
    double stdWeight;
    stdWeight = 22 * (height * height);

    /* 出力 */
    if(bmi >= 25) {
        printf("BMIは%.1f、肥満です\n", bmi);
        printf("身長%.1fの標準体重は%.1fkgです\n", height*100, stdWeight);
    } else {
        printf("BMIは%.1f、肥満ではありません\n", bmi);
    }

    return 0;
}
