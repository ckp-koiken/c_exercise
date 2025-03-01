#include <stdio.h>

int main(void) {
    char *hoshi[10] = {"hiroto", "yuuma", "souta", "minato", "ren", NULL};
    int i;

    for (i = 0; hoshi[i] != NULL; i++) { // 空ポインタを見つけるまで
        printf("%s\n", hoshi[i]);
    }
    return 0;
}