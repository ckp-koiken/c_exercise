#include <stdio.h>
#include <string.h>

struct employee {
    char family_name[25], first_name[25];
    int birth_year, birth_month, birth_day;
    int salary;
};

int main(void) {
    struct employee x;

    strcpy(x.family_name, "Ninomiya");
    strcpy(x.first_name, "Takayuki");
    x.birth_year = 2017;
    x.birth_month = 3;
    x.birth_day = 15;
    x.salary = 900;

    printf("氏名: %s %s\n", x.family_name, x.first_name);
    printf("生年月日: %d年%d月%d日\n", x.birth_year, x.birth_month, x.birth_day);
    printf("時給 %d円\n", x.salary);
    return 0;
}