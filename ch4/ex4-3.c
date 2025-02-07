#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
void wait_enter(void);

int roll_dice(void) {
    return rand() % 6 + 1;
}

void wait_enter(void) {
    char dummy;
    printf("サイコロを振るにはエンターキーを押してください ");
    scanf("%c", &dummy);
}

int main(void) {
    int c_hand1, c_hand2, c_hand_total, y_hand1, y_hand2, y_hand_total;
    srand(time(0));

    printf("コンピュータ ");
    c_hand1 = roll_dice();
    c_hand2 = roll_dice();
    c_hand_total = c_hand1 + c_hand2;
    printf("%d + %d = %d点\n", c_hand1, c_hand2, c_hand_total);

    wait_enter();
    y_hand1 = roll_dice();
    printf("1つめは%d\n", y_hand1);

    wait_enter();
    y_hand2 = roll_dice();
    printf("2つめは%d\n", y_hand2);
    y_hand_total = y_hand1 + y_hand2;
    printf("合計%d点\n", y_hand_total);

    if (c_hand_total == y_hand_total)
        printf("引き分け!\n");
    else if (c_hand_total > y_hand_total)
        printf("あなたの負けです\n");
    else
        printf("あなたの勝ち！！\n");
    
    return 0;
}
