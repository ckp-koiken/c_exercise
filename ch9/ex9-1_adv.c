#include <stdio.h>
#include <string.h>

struct employee {
    char family_name[25], first_name[25];
    int birth_year, birth_month, birth_day;
    int salary;
};

int main(void) {
    struct employee x;

    printf("氏？");
    scanf("%s", x.family_name);
    printf("名？");
    scanf("%s", x.first_name);

    printf("生年月日[年 月 日]？");
    scanf("%d", &x.birth_year);
    scanf("%d", &x.birth_month);
    scanf("%d", &x.birth_day);
    printf("時給？");
    scanf("%d", &x.salary);

    printf("氏名: %s %s\n", x.family_name, x.first_name);
    printf("生年月日: %d年%d月%d日\n", x.birth_year, x.birth_month, x.birth_day);
    printf("時給 %d円\n", x.salary);
    return 0;
}