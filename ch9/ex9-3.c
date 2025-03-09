#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct date {
    int year, month, day;
};

struct preca {
    char name[100];
    struct date exp;
    int price, id, secret;
};

int main(void){
    struct preca x = {"C-Preca", {2030, 12, 31}, 1000, 0, 0};

    srand(time(0));
    for (int i = 0; i <= 5; i++) {
        x.id = i;
        x.secret = rand() % 10000;
        printf("%s #%d: %d円、有効期限%4d/%02d/%02d、コード%04d\n", x.name, x.id, x.price, x.exp.year, x.exp.month, x.exp.day, x.secret);
    }

    return 0;
}