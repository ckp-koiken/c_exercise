#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct preca {
    char name[100];
    int year, month, day;
    int price, id, secret;
};

int main(void) {
    struct preca template = {"C-Preca", 2030, 12, 31, 1000, 0, 0};
    struct preca x, y, z;

    srand(time(0));
    x = template; 
    x.id = 1;
    x.secret = rand() % 10000;
    printf("%s #%d: %d円、有効期限%4d/%02d/%02d、コード%04d\n", x.name, x.id, x.price, x.year, x.month, x.day, x.secret);

    y = template; 
    y.id = 2;
    y.secret = rand() % 10000;
    printf("%s #%d: %d円、有効期限%4d/%02d/%02d、コード%04d\n", y.name, y.id, y.price, y.year, y.month, y.day, y.secret);

    z = template; 
    z.id = 2;
    z.secret = rand() % 10000;
    printf("%s #%d: %d円、有効期限%4d/%02d/%02d、コード%04d\n", z.name, z.id, z.price, z.year, z.month, z.day, z.secret);
    return 0;
}