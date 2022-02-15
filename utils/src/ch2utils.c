#include "ch2utils.h"

int htoi(char s[])
{
    int i, res;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    else
        i = 0;

    res = 0;
    for (; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') ||
           (s[i] >= 'a' && s[i] <= 'f');
         ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            res = 16 * res + (s[i] - '0');
        else if(s[i] >= 'A' && s[i] <= 'F')
            res = 16 * res + (s[i] - 'A' + 10);
        else if(s[i] >= 'a' && s[i] <= 'f')
            res = 16 * res + (s[i] - 'a' + 10);
    }
    return res;
}
