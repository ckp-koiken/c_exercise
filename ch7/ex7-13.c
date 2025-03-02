#include <stdio.h>
void show_group(char *name, char *v[]);

// name: に続けて、vの内容を添字付きで表示する
void show_group(char *name, char *v[]) {
    printf("%s:", name);
    for (int i = 0; v[i] != NULL; i++)
        printf(" %d:%s", i, v[i]);
    putchar('\n');
}

int main(void) {
    char *hoshi[10] = {"hiroto", "yuuma", "souta", "minato", "ren", NULL};
    char *tsuki[10] = {"aoi", "haruna", "yui", NULL};
    int i, to, from;

    show_group("Hoshi", hoshi);
    show_group("Tsuki", tsuki);

    printf("星組のどの人？（添字を入力）");
    scanf("%d", &from);
    printf("月組に入れる位置？");
    scanf("%d", &to);

    // コピー先を空ける
    // 空ポインタを探す
    for (i = 0; tsuki[i] != NULL; i++);  
    // 後ろから順に、後ろに一つずつずらす
    for(; i >= to; i--)
        tsuki[i+1] = tsuki[i];
    tsuki[to] = hoshi[from];  // ポインタをコピー

    show_group("Hoshi", hoshi);
    show_group("Tsuki", tsuki);

    return 0;
}