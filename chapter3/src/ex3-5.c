#include "ch3utils.h"
#include <stdio.h>

main() {
    /* Write a function itob(n,s,b) that converts the integer n into a base b character
     * representationin the string s. In particular, itob(n,s,16) formats n as a hexadecimal
     * integer in s.
     * */
    char buffer[100];
    itob(0xafafaf, buffer, 16);
    printf("%s\n", buffer);
}
