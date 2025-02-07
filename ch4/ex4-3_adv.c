#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int card_draw(void);

int card_draw(void) {
    int card;
    card = (rand() % 4 + 1) * 100 + (rand() % 10 + 2);
    return card;
}

void wait_enter(void) {
    char dummy;
    printf("カードを引くにはエンター");
    scanf("%c", &dummy);
}

int main(void) {
    int c_card1, c_card2, c_cards_total, y_card1, y_card2, y_cards_total;
    srand(time(0));
    printf("コンピュータ");
    c_card1 = card_draw();
    c_card2 = card_draw();
    c_cards_total = c_card1 + c_card2;
    printf("%d %d 合計%d点\n", c_card1, c_card2, c_cards_total);

    wait_enter();

    y_card1 = card_draw();
    y_card2 = card_draw();
    y_cards_total = y_card1 + y_card2;
    printf("1枚目 %d\n", y_card1);
    printf("2枚目 %d\n", y_card2);
    printf("合計%d点\n", y_cards_total);

    if (c_cards_total == y_cards_total)
        printf("引き分け\n");
    else if (c_cards_total == y_cards_total)
        printf("あなたの負け…\n");
    else 
        printf("あなたの勝ち！！\n");

    return 0;
}
