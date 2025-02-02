#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    unsigned int seed;
    int you, com;
    printf("あなたの手 ぐう=0 ちょき=1 ぱあ=2 ? ");
    scanf("%d", &you);

    // コンピュータの手
    srand(time(0)); // time(0)をseedとして乱数を発生
    com = rand() % 3; // 0-2の整数の乱数
    printf("コンピュータ ");
    switch (com) {
        case 0:
            printf("ぐう ");
            break;
        case 1:
            printf("ちょき ");
            break;
        case 2:
            printf("ぱあ ");
            break;
    }

    // あなたの手
    printf("あなた ");
    switch (you) {
        case 0:
            printf("ぐう ");
            break;
        case 1:
            printf("ちょき ");
            break;
        case 2:
            printf("ぱあ ");
            break;
    }
    printf("\n");

    // 勝敗判断
    if (you == com)
        printf("あいこです\n");
    else if ((you + 1) % 3 == com) // 3を法とする合同を利用する
        printf("あなたの勝ちです！\n");
    else 
        printf("あなたの負けです...\n");

    return 0;
}
