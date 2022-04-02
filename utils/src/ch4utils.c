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

double m_atof(char s[])
{
    double val, power, exp;
    int i, sign, exp_sign;

    power = 1.0;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
    {
        i++;
        for (; isdigit(s[i]); i++)
        {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0.0; isdigit(s[i]); i++)
            exp = 10.0 * exp + (s[i] - '0');
        for (; exp > 0.0; exp--)
        {
            power = (exp_sign > 0.0) ? power / 10.0 : power * 10.0;
        }
    }
    return sign * val / power;
}
