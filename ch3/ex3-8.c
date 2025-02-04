#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int you, com, money;
    srand(time(0));
    money = 200;

    while (100 <= money && money < 500) {
        // じゃんけんを所持金制限以内だったら繰り返す
        money -= 100;
        printf("掛け金を払いました。所持金%d円\n", money);

        // ここからじゃんけん(3-7と同じ)
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

            if (you != com)
                break;
            printf("あいこでしょ\n");

        }

        // 勝敗判断
        if ((you + 1) % 3 == com) {
            printf("あなたの勝ちです！\n");
            money += 200;
        } else {
            printf("あなたの負けです...\n");
        }

        printf("所持金は%d円です\n", money);

    }

    // じゃんけん終了後の表示
    printf("ゲーム終了です。");
    if (money == 0) 
        printf("残念でした。\n");
    else
        printf("おめでとう！\n");

    return 0;
}
