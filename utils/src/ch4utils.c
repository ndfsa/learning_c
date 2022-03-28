#include "ch4utils.h"

int strrindex(char s[], char t[])
{
    int i, j;
    int start;
    i = j = 0;
    start = 0;
    while (s[i++] != '\0')
    {
        if (j == 0)
            start = i;
        if (t[j] == '\0')
            return start;
        if (s[i] != t[j])
        {
            j = 0;
            continue;
        }
        j++;
    }
    return -1;
}
