#include <stdio.h>

int main()
{
    int i = 425;
    short int j = 17;
    unsigned int u = 0xf179U;
    long int l = 75000L;
    long long int L = 0x1234567812345678LL;
    printf("Integers:\n");
    printf("%i, %o, %x, %u\n", i, i, i, i);
    printf("%x, %X, %#x, %#X\n", i, i, i, i);
    printf("%+i, %i, %5i, % 5i, %05i, %.7i\n", i, i, i, i, i, i);
    printf("%i, %o, %x, %u\n", j, j, j, j);
    printf("%i, %o, %x, %u\n", u, u, u, u);
    printf("%ld, %lo, %lx, %lu\n", l, l, l, l);
    printf("%lli, %llo, %llx, %llu\n", L, L, L, L);
    return 0;
}

