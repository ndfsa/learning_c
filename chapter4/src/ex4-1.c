#include "ch4utils.h"
#include <stdio.h>

main() {
    /* Write the function strrindex(s,t), which returns the position of the rightmost occurrence
     * of t in s, or -1 if there is none.
     * */
    char word[] = "aaaaaccaaaaaaccaaaa";
    char pattern[] = "cc";
    printf("%s %d\n", word, strrindex(word, pattern));
    printf("%s %d\n", word, strindex(word, pattern));
}
