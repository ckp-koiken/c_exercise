#include <stdio.h>

int main(void) {
    char tsuki[][15] = {"aoi", "haruna", "yui"};

    for (int i = 0; i < sizeof(tsuki)/sizeof(tsuki[0]); i++)
        printf("%d: %s\n", i, tsuki[i]);
    return 0;
}