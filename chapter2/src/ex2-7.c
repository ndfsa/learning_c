#include <stdio.h>
#include "ch2utils.h"

main()
{
    /* Write a function invert(x, p, n) that returns x with the n bits that begin at position p
     * inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
     * */

    printf("%d\n", invert(0xff, 2, 4));
}
