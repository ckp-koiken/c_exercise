#include <stdio.h>

void chomp(char *p);

void chomp(char *p) {
    while (*p != '\0') {
        if (*p == '\n')
            *p = '\0';
        p++;
    }
}

int main(void) {
    char name[100];

    printf("あなたの名前は？");
    fgets(name, sizeof(name), stdin);
    chomp(name);
    printf("勇者 %s よ、よくぞまいった\n", name);
    return 0;
}