#include <stdio.h>

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))

void calc_ttime(int *routep[], int ttimep[]);
void show_routes(int *routep[], int ttimep[]);

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

    calc_ttime(routes, ttime);   // 所要時間を計算してttimeに入れる
    show_routes(routes, ttime); // 一覧を表示

    return 0;
}
