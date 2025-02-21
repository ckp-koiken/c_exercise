#include <stdio.h>

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))

void calc_ttime(int *routep[], int ttimep[]);
void show_routes(int *routep[], int ttimep[]);
void sort_routes(int nelems, int *routep[], int ttimep[]);

// 各経路の所要時間を計算する
void calc_ttime(int *routep[], int ttimep[]) {
    while (*routep != NULL) {
        *ttimep = 0;
        for (int *p = *routep; *p > 0; p++)
            *ttimep += *p;
        routep++;
        ttimep++;
    }
}

// 経路の一覧を表示する
void show_routes(int *routep[], int ttimep[]) {
    for (int **rp = routep; *rp != NULL; rp++, ttimep++) {
        printf("経路#%d: ", (int)(rp-routep)+1);  // rp-routepが添字、ptrdiff_t型
        for (int *p = *rp; *p > 0; p++)
            printf(" %d分", *p);
        printf(", 合計%d分\n", *ttimep);
    }
}

// 経路をソートする
void sort_routes(int nelems, int *routep[], int ttimep[]) {
    printf("時間順にします\n");
    // バブルソート
    for (int i = 0; i < nelems-1; i++) {  // iは0から1つずつ増やす
        for (int j = nelems-2; j >= i; j--) {  // 後ろから逆順に1まで
            if (ttimep[j] > ttimep[j+1]) {  // 隣り合った2つで
                int d, *rp;               // 前が小さくなるように入れ替える
                d = ttimep[j]; ttimep[j] = ttimep[j+1]; ttimep[j+1] = d;
                rp = routep[j]; routep[j] = routep[j+1]; routep[j+1] = rp;
            }
        }
    }
}

int main(void) {
    // ルートごとの配列を用意
    int route1[] = {5, 35, 6, -1},
        route2[] = {6, 9, 20, 5 -1},
        route3[] = {20, 35, -1},
        route4[] = {7, 19, 18, 5, -1},
        route5[] = {33, 21, -1};
    // ルート配列を指すポインタ
    int *routes[] = {route1, route2, route3, route4, route5, NULL};
    int ttime[NELEMS(routes)-1];   // 各経路の所要時間
    int n = NELEMS(ttime);  // 経路数

    // ルート変更のための変数
    int route_num, route_order;

    calc_ttime(routes, ttime);   // 所要時間を計算してttimeに入れる
    show_routes(routes, ttime); // 一覧を表示
    sort_routes(n, routes, ttime);  // ソート



    show_routes(routes, ttime);  // 結果を表示

    printf("何番目の路線？\n");
    scanf("%d", &route_num);
    printf("いくつめの路線？\n");
    scanf("%d", &route_order);

    // 変更の処理
    
    // バブルソートの処理


    return 0;
}
