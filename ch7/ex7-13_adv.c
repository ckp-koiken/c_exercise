#include <stdio.h>

int main(void) {
    char *hoshi[10] = {"hiroto", "yuuma", "souta", "minato", "ren", NULL};
    int i, j, c, place;
    char name[10];

    for (i = 0; hoshi[i] != NULL; i++) {
        printf("%d:%s\n", i, hoshi[i]);
    }

    printf("名前？");
    j = 0;
    while ((c = getchar()) != '\n') {
        name[j] = c;
        j++;
    }

    printf("入れる位置？");
    scanf("%d", &place);

    // 後ろから順に、後ろに一つずつずらす
    for (i = 0; hoshi[i] != NULL; i++); 
    for(; i >= place; i--)
        hoshi[i+1] = hoshi[i];
    hoshi[place] = name;

    for (i = 0; hoshi[i] != NULL; i++) {
        printf("%d:%s\n", i, hoshi[i]);
    }

    return 0;
}