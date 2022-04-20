#include "ch4utils.h"
#include "ch2utils.h"

int strindex(char s[], char t[]) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strrindex(char s[], char t[]) {
    int i, j, k;
    int m_size_s = m_strlen(s), m_size_t = m_strlen(t);

    for (i = m_size_s - 1; i >= 0; i--) {
        for (j = i, k = m_size_t - 1; k >= 0 && s[j] == t[k]; j--, k--)
            ;
        if (k == 0 && t[k] == s[i])
            return i;
    }
    return -1;
}

double m_atof(char s[]) {
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
    if (s[i] == '.') {
        i++;
        for (; isdigit(s[i]); i++) {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0.0; isdigit(s[i]); i++)
            exp = 10.0 * exp + (s[i] - '0');
        for (; exp > 0.0; exp--) {
            power = (exp_sign > 0.0) ? power / 10.0 : power * 10.0;
        }
    }
    return sign * val / power;
}
