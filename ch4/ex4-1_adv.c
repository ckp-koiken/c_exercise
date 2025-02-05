#include <stdio.h>
#include <math.h>

void plot(double y);


void plot(double y) {
    for (int i = -20; i <= 20; i++) {
        int x = (int)(y*20); // 型をintに揃える
        if(i == x)
            printf("*");
        else if(i == 0)
            printf("|");
        else
            printf(" ");
    }
    printf("\n");
}


int main(void) {
    int d;
    double rad, s;
    for (int i = -12; i <= 12; i++) { // 定義域が-pi <= x <= piなので
        d = i * 15; // 15度ずつ区切る

        rad = d * M_PI / 180; // ラジアンに直す。2piが360度。

        s = sin(rad); // sin()関数に渡す コンパイル時に-lmオプションを付ける

        plot(s);
    }
    return 0;
}

// NOTE: 
// cc ex4-1_adv.c -lm
// 最後に-lmをつけると動く
