#include "ch3utils.h"
#include <stdio.h>

main() {
    /* In a two's complement number representation, our version of itoa does not handle the largest
     * negative number, that is, the value of n equal to -(2^(wordsize-1)). Explain why not. Modify
     * it to print that value correctly, regardless of then machine it runs.
     * A. because of how the two's complement works, the expression n = -n does not have any
     * effect when using the "largest" negative number, when trying to write 2147483648 to a signed
     * (32 bit) int, the variable overflows to -2147483648 and the instruction is effectively
     * ignored.
     * */
    char buf[100];
    itoa(-2147483648, buf);
    printf("%s\n", buf);
}
