#include <stdio.h>

int setbits(int x, int p, int n, int y);
main()
{
    printf("The result is: %d\n", setbits(90, 5, 4, 147));
}

int setbits(int x, int p, int n, int y)
{
    /* set the n bits in position p from x,
     * to the n bits in position p from y */
    int mask = ~(~0 << n) << (p + 1 - n);
    return x & ~mask | y & mask;
}
