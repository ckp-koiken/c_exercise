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

    /* 出力 */
    if(bmi >= 25)
        printf("BMIは%.1f、肥満です\n", bmi);
    else
        printf("BMIは%.1f、肥満ではありません\n", bmi);

    return 0;
}
