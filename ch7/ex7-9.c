#include <stdio.h>

int hash(char *pw) {
    int i;
    long int h;

    // TODO: もっとわかりやすい計算方法がないか探す
    h = 0;
    for (i = 0; pw[i] != '\0'; i++)
        h = h * 31 + pw[i];     // hをlong intで計算
    return h % 4093;            // 戻り値はint
}

int main(void) {
    char pw[100];
    int i, pw_hash, h;

    printf("パスワードを登録してください: ");
    scanf("%99s", pw);      // 入力は99文字まで
    pw_hash = hash(pw);
    printf("ハッシュ値 %d\n", pw_hash);

    for (i = 0; i < 3; i++) {
        printf("パスワード？");
        scanf("%99s", pw);      // 入力は99文字まで
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