#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEIBOFILE "meibo.txt"  // 元の名簿ファイル
#define OUTFILE "new_meibo.txt"  // 新しく作るファイル名

enum {
    NAMESIZE = 55+1,  // 氏名の最大文字数+空文字1バイト
    MEIBOSIZE = 100,  // 名簿の最大人数
    LINEBUFSIZE = 1024 // 一行読むバッファの大きさ
};

struct student {
    int id;
    char name[NAMESIZE];
};

int read_meibo(struct student *people, int n);
void sort_meibo(struct student *people, int n);
void write_meibo(struct student *people, int n);

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

void sort_meibo(struct student *people, int n) {
    struct student tmp;

    // バブルソート
    for (int i = 0; i < n-1; i++) {
        for (int j = n-2; j >= i; j--) {
            if (people[j+1].id < people[j].id) {
                tmp = people[j];
                people[j] = people[j+1];
                people[j+1] = tmp;
            }
        }
    }
}

void write_meibo(struct student *people, int n) {
    FILE *fp;

    // 新しい名簿ファイルをオープン
    if ((fp = fopen(OUTFILE, "w")) == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // 項目を書き出す
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d %s\n", people[i].id, people[i].name); 
    fclose(fp);
}

int main(void) {
    struct student people[MEIBOSIZE];
    int n;

    n = read_meibo(people, MEIBOSIZE);
    sort_meibo(people, n);  // peopleの内容を学生番号順にソート
    write_meibo(people, n);  // 新しいファイルに書き出す

    return 0;
}