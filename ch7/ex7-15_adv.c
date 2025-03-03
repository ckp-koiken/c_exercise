#include <stdio.h>

int main(void) {
    char tsuki[][15] = {"aoi", "haruna", "yui"};
    int num;

    for (int i = 0; i < sizeof(tsuki)/sizeof(tsuki[0]); i++)
        printf("%d: %s\n", i, tsuki[i]);

    printf("削除する要素の添字は？");
    scanf("%d", &num);

    // 配列を後ろから見て指定された添字の次の要素を添字の要素に上書きする（削除）
    for (int j = num; j != 0; j--) {
        for (int k = 0; tsuki[j][k] != '\0'; k++) {
            tsuki[j][k] = tsuki[j+1][k];
        }
    }

    // 指定した添字の次の要素を削除する
    // TODO: 添字だけ残ってしまうので要素そのものを削除できるように要改良
    for (int j = num+1; j < sizeof(tsuki)/sizeof(tsuki[0]); j++) {
        for (int k = 0; tsuki[j][k] != '\0'; k++) {
            tsuki[j][k] = '\0';
        }
    }

    for (int i = 0; i < sizeof(tsuki)/sizeof(tsuki[0]); i++)
        printf("%d: %s\n", i, tsuki[i]);


    return 0;
}