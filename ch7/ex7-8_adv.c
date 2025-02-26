#include <stdio.h>

void get_line(char *p, size_t size, char *q);

void get_line(char *p, size_t size, char *q) {
    printf("%s\n", *q);
    fgets(p, sizeof(*p), stdin);
    while (*p != '\0') {
        if (*p == '\n')
            *p = '\0';
    }
}

int main(void) {
    char s[1024];

    get_line(s, 100, "あなたの名前は？");

    return 0;
}