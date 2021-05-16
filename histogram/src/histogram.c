#include <stdio.h>
#define ASCII_LIM 128

main()
{
    float counter[ASCII_LIM];
    float n;

    int ntab, nspaces, nl, c, i;

    for (i = 0; i < ASCII_LIM; ++i)
    {
        counter[i] = 0;
    }

    while ((c = getchar()) != EOF && c < 128)
    {
        ++counter[c];
        ++n;
    }

    for (i = 0; i < ASCII_LIM; ++i)
    {
        if (counter[i] > 0)
        {
            printf("%3d: %5.f\t%5.1f%% ", i, counter[i], counter[i] / n * 100.0);
            int j;
            for (j = 0; j < 50.0 * (counter[i] / n); ++j)
            {
                putchar('|');
            }
            printf("\n");
        }
    }

    return 0;
}
