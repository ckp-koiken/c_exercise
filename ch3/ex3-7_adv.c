#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num, ans, count, check;
    srand(time(0));
    num = rand() % 10 + 1;
    printf("1から10までのどれかの数を用意しました！\n");
    count = 0;
    for (;;) {
        printf("いくつだと思う？");
        scanf("%d", &ans);
        if(ans == num) {
            printf("正解！\n");
            break;
        } else if (ans < num) {
            check = 1;
            count++;
        } else {
            count++;
        }

        if(count == 3) {
            printf("残念でした\n");
            break;
        }

        switch (check) {
            case 1:
                printf("もっと大きいよ\n");
                break;
            case 2:
                printf("もっと小さいよ\n");
                break;
        }
    }

    
    return 0;
}
