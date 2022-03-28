#include <stdio.h>
#include "ch4utils.h"

main()
{
    /* Write the function strrindex(s,t), which returns the position of the rightmost occurrence
     * of t in s, or -1 if there is none.
     * */
    char word[] = "This is a test resistance is futile, get tested.";
    char pattern[] = "test";
    printf("%s %d", word, strrindex(word, pattern));
}
