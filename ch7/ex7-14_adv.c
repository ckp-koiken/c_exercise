#include <stdio.h>
void show_array(char *v[]);

void show_array(char *v[]) {
    for (int i = 0; v[i] != NULL; i++) {
        printf("%d:%s ", i, v[i]);
    }
    printf("\n");
}

int main(void) {
    char *platon[10] = {"一番", "大切な", "ことは", "単に", "生きること", "でなく", "善く", "生きること", "である", NULL};
    int i, from, count;

    show_array(platon);
    
    // 削除領域の質問
    printf("削除開始の位置？");
    scanf("%d", &from);
    printf("いくつ？");
    scanf("%d", &count);

    // 対象となる範囲を削除する
    for (from; platon[from] != NULL; from++) {
        platon[from] = platon[from+count];
    }

    // 配列の一連の内容を表示
    for (i = 0; platon[i] != NULL; i++)
        printf("%s", platon[i]);
    
    printf("\n");
    return 0;
}