#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int card_draw(void);
void wait_enter(void);
char check_pattern(int card);
int check_num(int card);

int card_draw(void) {
    int card;
    card = (rand() % 4 + 1) * 100 + (rand() % 10 + 2);
    return card;
}

char check_pattern(int card) {
    int check;
    check = card / 100;
    switch (check) {
        case 1:
            return 'S';
        case 2:
            return 'H';
        case 3:
            return 'C';
        case 4:
            return 'D';
    }
}

int check_num(int card) {
        return card % 10;
}

void wait_enter(void) {
    char dummy;
    printf("カードを引くにはエンター");
    scanf("%c", &dummy);
}

int main(void) {
    int c_card1, c_card2, c_cards_total, y_card1, y_card2, y_cards_total;
    int c_card1_pat, c_card2_pat, c_card1_num, c_card2_num;
    int y_card1_pat, y_card2_pat, y_card1_num, y_card2_num;
    srand(time(0));
    printf("コンピュータ");
    c_card1 = card_draw();
    c_card2 = card_draw();
    c_card1_pat = check_pattern(c_card1);
    c_card2_pat = check_pattern(c_card2);
    c_card1_num = check_num(c_card1);
    c_card2_num = check_num(c_card2);
    c_cards_total = c_card1_num + c_card2_num;
    printf("%c%d %c%d 合計%d点\n", c_card1_pat, c_card1_num, c_card2_pat, c_card2_num, c_cards_total);

    wait_enter();

    y_card1 = card_draw();
    y_card2 = card_draw();
    y_card1_pat = check_pattern(y_card1);
    y_card2_pat = check_pattern(y_card2);
    y_card1_num = check_num(y_card1);
    y_card2_num = check_num(y_card2);
    y_cards_total = y_card1_num + y_card2_num;
    printf("1枚目 %c%d\n", y_card1_pat, y_card1_num);
    printf("2枚目 %c%d\n", y_card2_pat, y_card2_num);
    printf("合計%d点\n", y_cards_total);

    if (c_cards_total == y_cards_total)
        printf("引き分け\n");
    else if (c_cards_total > y_cards_total)
        printf("あなたの負け…\n");
    else 
        printf("あなたの勝ち！！\n");

    return 0;
}
