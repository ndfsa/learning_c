#include <stdio.h>
#include "fahrenheit.h"

/* Exercise 1-3 */
void ftoc()
{
    /* print fahrenheit-celcius table
     * for fahr = 0, 20, ..., 300 */

    float fahr;
    printf("fahrenheit | celcius\n--------------------\n");

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    {
        printf("%10.3f | %7.3f\n", fahr, tocelcius(fahr));
    }
}

/* Exercise 1-5 */
void rev_ftoc()
{
    /* print fahrenheit-celcius table
     * for fahr = 0, 20, ..., 300 */

    float fahr;
    printf("fahrenheit | celcius\n--------------------\n");

    for (fahr = 300; fahr <= 0; fahr = fahr - 20)
    {
        printf("%10.3f | %7.3f\n", fahr, tocelcius(fahr));
    }
}

float tocelcius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}
