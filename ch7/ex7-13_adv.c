#include <stdio.h>
#include <stdlib.h>
void show_group(char *group[]);

void show_group(char *group[]) {
    for (int i = 0; group[i] != NULL; i++) {
        printf("%d:%s\n", i, group[i]);
    }    
}

int main(void) {
    char *hoshi[10] = {"hiroto", "yuuma", "souta", "minato", "ren", NULL};
    int i, c, place;
    // char name[10];  // 直接配列を確保してもよい
    
    // 名前を入れる領域を確保（10文字）
    char *name;
    if ((name = malloc(sizeof(char) * 10)) == NULL)
        exit(1);

    show_group(hoshi);

    printf("名前？");
    i = 0;
    while ((c = getchar()) != '\n') {
        name[i] = c;
        i++;
    }

    printf("入れる位置？");
    scanf("%d", &place);

    // 後ろから順に、後ろに一つずつずらす
    for (i = 0; hoshi[i] != NULL; i++); 
    for(; i >= place; i--)
        hoshi[i+1] = hoshi[i];
    hoshi[place] = name;

    show_group(hoshi);
    
    // 領域解放
    free(name);

    return 0;
}