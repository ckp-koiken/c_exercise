#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEIBOFILE "meibo.txt"
enum {
    NAMESIZE = 55+1,  // 氏名の最大文字数+空文字1バイト
    MEIBOSIZE = 100,  // 名簿の最大人数
    LINEBUFSIZE = 1024 // 一行読むバッファの大きさ
};

struct student {
    int id;
    char name[NAMESIZE];
};

// 構造体配列peopleと最大人数nを受け取って読み込んだ項目数を返す
int read_meibo(struct student *people, int n) {
    FILE *fp;  // 入力ストリーム
    char buf[LINEBUFSIZE], *p, *name;  // 入力buf
    int i;

    // 名簿ファイルを開く
    if ((fp = fopen(MEIBOFILE, "r")) == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        // 一行ずつ読み込んで改行文字を除去
        if ((p = strchr(buf, '\n')) != NULL)
            *p = '\0';

        // カンマを探す
        if ((p = strchr(buf, ',')) == NULL) {
            fprintf(stderr, "変なデータです：%s\n", buf);
            continue;  // カンマが無ければ変な行なので無視
        }
        name = p + 1;  // カンマの次からが氏名。nameポインタで指す
        *p = '\0';  // カンマを空文字で潰す。bufが学生番号のみになる
        people[i].id = atoi(buf);  // 構造体に学生番号を入れる
        strncpy(people[i].name, name, NAMESIZE-1); // 氏名を入れる
        people[i].name[NAMESIZE-1] = '\0';  // 長すぎた場合のため
        if (++i >= n)
            break;  // 最大人数に達したらループを終了
    }

    fclose(fp);
    return i;
}

int main(void) {
    struct student people[MEIBOSIZE];
    int n;

    n = read_meibo(people, MEIBOSIZE);
    for (int i = 0; i < n; i++)
        printf("[%d] %s\n", people[i].id, people[i].name);

    return 0;
}