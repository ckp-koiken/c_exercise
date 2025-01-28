#include <stdio.h>

int main(void) {
    int i;

    printf("sizeof(int) = %zu \n", sizeof(int));
    printf("sizeof(i) = %zu \n", sizeof(i));
    printf("sizeof(char) = %zu \n", sizeof(char));
    printf("sizeof(short int) = %zu \n", sizeof(short int));
    printf("sizeof(long int) = %zu \n", sizeof(long int));
    printf("sizeof(float) = %zu \n", sizeof(float));
    printf("sizeof(double) = %zu \n", sizeof(double));

    printf("---------------------------------------\n");
    
    unsigned short int j;
    unsigned int k;
    unsigned long int l;
    printf("sizeof(unsigned short int) = %zu \n", sizeof(unsigned short int));
    printf("sizeof(j) = %zu \n", sizeof(j));
    printf("sizeof(unsigned int) = %zu \n", sizeof(unsigned int));
    printf("sizeof(k) = %zu \n", sizeof(k));
    printf("sizeof(unsigend long int) = %zu \n", sizeof(unsigned long int));
    printf("sizeof(l) = %zu \n", sizeof(l));

    return 0;
}
