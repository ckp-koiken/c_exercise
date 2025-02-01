#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MAX * 2 = %d\n", INT_MAX * 2); // overflow
    printf("INT_MAX * 2 / 3 = %d\n", INT_MAX * 2 / 3); // overflow
    printf("INT_MAX / 3 * 2 = %d\n", INT_MAX / 3 * 2);
    
    return 0;
}
