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
        else if (s[i] >= 'A' && s[i] <= 'F')
            res = 16 * res + (s[i] - 'A' + 10);
        else if (s[i] >= 'a' && s[i] <= 'f')
            res = 16 * res + (s[i] - 'a' + 10);
    }
    return res;
}

int m_strlen(char s[])
{
    int i;

    i = 0;
    while (s[i++] != '\0')
        ;
    return i - 1;
}

void squeeze(char s1[], char s2[])
{
    int len_s1, len_s2, i, j;

    len_s1 = m_strlen(s1);
    len_s2 = m_strlen(s2);

    for (i = 0; i < len_s1; i++)
        for (j = 0; j < len_s2; j++)
            if (s1[i] == s2[j])
                s1[i] = -s1[i];

    i = j = 0;
    while (s1[i] != '\0')
        if (s1[i] > 0)
            s1[j++] = s1[i++];
        else
            i++;
    if (i>0)
        s1[j] = '\0';
}
