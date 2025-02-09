#include <stdio.h>

// #define age(x) ((x) < 18 ? (x) : 20)

int age(int x) {
    if (x < 18)
        return x;
    else
        return 20;
}

int main(void) {
    int n;

    n = 1;
    while (n <= 22)
        printf("%d ", age(n++));
    printf("\n");
    
    return 0;
}
