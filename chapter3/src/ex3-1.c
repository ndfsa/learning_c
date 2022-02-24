#include "ch3utils.h"
#include <stdio.h>

#define LIM 1000000

main()
{
    /* Our binary search makes two tests inside the loop, when one would suffice (at the rpice of
     * more tests outside). Write a version with only one test inside the loop and measure the
     * difference in run-time.
     * A. binsearch no changes: 53.7 ms ±   3.4 ms
     * binsearch with changes: 49.9 ms ±   2.2 ms
     * (release build)
     * */

    int arr[LIM];
    int i, err;

    for (i = 0; i < LIM; i++)
        arr[i] = i;

    err = 0;
    for (i = 0; i < LIM; i++)
        err += i - binsearch(i, arr, LIM);

    printf("%d\n", err);
    return 0;
}
