#include <stdio.h>

main()
{
    long character_count;

    while (getchar() != EOF)
        ++character_count;

    printf("%4ld", character_count);
}
