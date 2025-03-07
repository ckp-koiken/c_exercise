#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"


// 1行を読み込む共通の処理
static void get_line(char *p, int size) {
    do {
        fgets(p, size, stdin);
    } while (*p == '\n');
    while (*p) {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }
}

// 本の情報を外部変数に読み込む
void read_books(void) {
    char *p;

    nbooks = 0;
    for (;;) {
        if ((p = malloc(TITLESIZE)) == NULL) {
            perror("malloc");
            break;
        }
        printf("#%d 題名: ", nbooks);
        get_line(p, TITLESIZE);
        if (p[0] == '.' && p[1] == '\0') {
            free(p);
            return;
        }
        books[nbooks] = p;
        printf("#%d 値段: ", nbooks);
        scanf("%d", &prices[nbooks]);
        nbooks++;
    }
}