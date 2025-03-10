#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[100];
};

void read_student(struct student *p);

void read_student(struct student *p) {
    char *q;

    printf("氏名？");
    fgets(p->name, sizeof(p->name), stdin);
    // 改行文字を取り除く
    if ((q = strchr(p->name, '\n')) != NULL)
    *q = '\0';
    // strchrで与えられた文字列の中で当該文字が最初に出てくる位置のポインタを返す
    
    printf("学生番号？");
    scanf("%d", &p->id);
}

int main(void) {
    struct student x;

    read_student(&x);
    printf("学生番号%d 氏名: %s\n", x.id, x.name);
    return 0;
}