#include <stdio.h>

// TODO: 3桁ごとにカンマを入れる関数を追加

int main(void) {
    long int pop, area, density;
    printf("人口[人]？");
    scanf("%ld", &pop);
    printf("面積[平方km]");
    scanf("%ld", &area);
    density = pop / pop;

    printf("人口%ld人、面積%ld平方km、人口密度は%ld人/平方kmです\n", pop, area, density);
    return 0;
}
