#include <stdio.h>

enum { N = 100 };

int main(void) {
    int a[N+1] = { 0 }; // a[N]まで使いたいからN+1を指定
                        // 0が入っていると素数と判定（合成数にフラグを立てる）

    for (int i = 2; i <= N; i++) { // 2からNまでの整数を順に見る
        if (a[i] == 0) { // 該当する番手が0だったら(iが素数なら)倍数をふるい落とす
            for (int j = i * 2; j <= N; j += i) // iの倍数をふるい落とす
                a[j] = 1;
        }
    }
    
    // 素数を表示
    for (int i = 2; i <= N; i++) {
        if (a[i] == 0)
            printf("%d ", i);
    }

    printf("\n");
    
    return 0;
}
