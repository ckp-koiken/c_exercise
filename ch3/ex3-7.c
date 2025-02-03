#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int you, com;
    srand(time(0)); // time(0)をseedとして乱数を発生

    // 無限ループ。do-while文でもできる
    for (;;) {
        printf("あなたの手 ぐう=0 ちょき=1 ぱあ=2 ? ");
        scanf("%d", &you);

        // コンピュータの手
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

        if (you != com) // あなたとコンピュータの手が異なる場合ループを離脱して勝敗判断
            break;
        printf("あいこでしょ\n"); // 手が同じ場合あいことしてループ継続
    }

    // 勝敗判断
    if ((you + 1) % 3 == com) // 3を法とする合同を利用する
        printf("あなたの勝ちです！\n");
    else 
        printf("あなたの負けです...\n");

    return 0;
}
