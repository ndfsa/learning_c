#include <stdio.h>
#include "ch2utils.h"

main()
{
    /* Write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p
     * set to the rightmost n bits of y, leaving the other bits unchanged.
     * */

    printf("%d\n", setbits(0xff, 2, 4, 10));
}
