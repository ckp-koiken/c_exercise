#include <stdio.h>
#include <stdlib.h>

char *mgets(void) {
    char *p, *newp;
    int c;
    size_t sz = 1;      // 現在の領域を覚えておく変数

    if ((p = malloc(sz)) == NULL)
        return NULL;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            break;
        if ((newp = realloc(p, sz+1)) == NULL)
            break;
        p = newp;
        sz++;
        p[sz-2] = c;
    }
    p[sz-1] = '\0';
    return p;
}

int main(void) {
    char *vnam, *fnam;

    printf("ファーストネーム？");
    vnam = mgets();
    printf("ファミリーネーム？");
    fnam = mgets();
    printf("ようこそ、%s %sさん！\n", vnam, fnam);
    free(vnam);
    free(fnam);
    return 0;
}