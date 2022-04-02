#include <stdio.h>
#include "ch4utils.h"

main()
{
    /* Extend atof to handle scientific notation of the form 123.45e-6 where a floating point
     * number may be followed by e or E and an optionally signed exponent.
     * */
    char buffer[] = "123.45e-6";
    printf("%e\n", m_atof(buffer));
}
