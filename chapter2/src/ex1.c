#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
    printf("int: [%d %d]\n", INT_MIN, INT_MAX);
    printf("unsigned int: [%u %u]\n", 0, UINT_MAX);
    printf("short int: [%d %d]\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short int: [%u %u]\n", 0, USHRT_MAX);
    printf("long int: [%ld %ld]\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int: [%lu %lu]\n", 0L, ULONG_MAX);
    printf("char: [%d %d]\n", CHAR_MIN, CHAR_MIN);
    printf("unsigned char: [%d %d]\n", 0, UCHAR_MAX);
    printf("float: [%f %f]\n", FLT_MIN, FLT_MAX);
    printf("double: [%lf %lf]\n", DBL_MIN, DBL_MAX);
}
