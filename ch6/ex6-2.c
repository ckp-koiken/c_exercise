#include <stdio.h>

void cancel(int *np, int *dp);

void cancel(int *np, int *dp) {
    int fact = 2;
    
    while (fact <= *dp) {
        if (*np % fact == 0 && *dp % fact == 0) {
            *np /= fact;
            *dp /= fact;
        } else 
            fact++;
    }
}

int main(void) {
    int n, d;

    printf("分子？");
    scanf("%d", &n);
    printf("分母？");
    scanf("%d", &d);
    cancel(&n, &d);
    printf("約分すると %d/%d\n", n, d);
    
    return 0;
}
