#include "ch2utils.h"
#include <stdio.h>

main() {
    /* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x, explain
     * why. Use this observation to write a faster version of bitcount.
     * A. There are two cases for to take into account, first is if the rightmost bit is 1, in
     * which case:
     * (...)1 - 1 = (...)0
     * taking that result and using the & operator with the first value will always result in the
     * rightmost bit being 0.
     * The second case is if the rightmost bit is 0:
     * (...)10 - 1 = (...)01
     * (...)100 - 1 = (...)011
     * (...)1000 - 1 = (...)0111
     * the rightmost bit must "borrow" from it's left neighbor in order for the operation to be
     * completed, the result is the first number inverted (in binary terms) up until the rightmost
     * 1-bit. Applying the & operator will result in erasing the rightmost 1-bit.
     * */

    printf("%d\n", bitcount(0x1d));
}
