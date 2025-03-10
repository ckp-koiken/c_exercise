#include <stdio.h>

struct student {
    int id;
    char name[100];
};
void show_student(struct student *p);

void show_student(struct student *p) {
    printf("学生番号%d 氏名: %s\n", p->id, p->name);
}

int main(void) {
    struct student x = {1100, "Kawahara Hinata"};
    show_student(&x);
    return 0;
}