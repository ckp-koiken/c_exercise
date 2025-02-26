#include <stdio.h>
int hash(char *pw);
void ltrim(char *pw);

// TODO: 符号付きcharでpw[i]が負になりハッシュ値が狂うのを修正
int hash(char *pw) {
    int i;
    long int h;

    h = 0;
    for (i = 0; pw[i] != '\0'; i++)
        h = h * 31 + pw[i];     // hをlong intで計算
    return h % 4093;            // 戻り値はint
}

void ltrim(char *pw) {      // 改行コードを空文字に変換
    while (*pw != '\0') {
        if (*pw == '\n')
            *pw = '\0';
        pw++;
    }
}

int main(void) {
    char pw[100];
    int i, pw_hash, h;

    printf("パスワードを登録してください: ");
    // fgetsを使ってpwの上限を超えないように入力させる
    fgets(pw, sizeof(pw), stdin);
    ltrim(pw);  // 改行コードを取る
    pw_hash = hash(pw);
    printf("ハッシュ値 %d\n", pw_hash);

    for (i = 0; i < 3; i++) {
        printf("パスワード？");
        fgets(pw, sizeof(pw), stdin);
        ltrim(pw);  // 改行コードを取る
        h = hash(pw);
        printf("ハッシュ値 %d\n", h);
        if (h == pw_hash)       // ハッシュ値が一致したら
            break;              // breakする
        printf("パスワードが違います\n");
    }
    if (i < 3)      // 3回未満ならハッシュ値が一致
        printf("ログインしました！\n");
    else            // ループを回り切ったなら失敗
        printf("ログインに失敗しました…\n");
    return 0;
}