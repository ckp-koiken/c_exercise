#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct preca {
    char name[100];
    struct date {
        int year, month, day;
    } exp;
    int price, id, secret;
};

int main(void){
    struct preca cards[100];
    struct preca template = {"C-Preca", {2030, 12, 31}, 1000, 0, 0};
    int i, n;

    srand(time(0));
    printf("発行するカードの枚数？");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        cards[i] = template;
        cards[i].id = i + 1;
        cards[i].secret = rand() % 10000;
    }

    for (i = 0; i < n; i++) {
        printf("%s #%d: %d円、有効期限%4d/%02d/%02d、コード%04d\n", cards[i].name, cards[i].id, cards[i].price, cards[i].exp.year, cards[i].exp.month, cards[i].exp.day, cards[i].secret);
    }

    return 0;
}