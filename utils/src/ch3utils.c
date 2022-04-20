#include "ch3utils.h"
#include "ch1utils.h"

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    return (x == v[mid]) ? mid : -1;
}
void escape(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            i++;
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            i++;
            break;
        default:
            s[j++] = t[i++];
            break;
        }
    }
    s[j] = '\0';
}
void rescape(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
        case '\\':
            if (t[++i] == '\0')
                break;
            else if (t[i] == 'n')
                s[j++] = '\n';
            else if (t[i] == 't')
                s[j++] = '\t';
            else
                s[j++] = t[i];
            i++;
            break;
        default:
            s[j++] = t[i++];
            break;
        }
    }
    s[j] = '\0';
}
void expand(char s1[], char s2[]) {
    int i, j, k;
    for (i = 0, j = 0; s1[i] != '\0'; i++)
        if (s1[i] == '-' && i > 0 && IS_ALPHANUMERIC(s1[i - 1]) && IS_ALPHANUMERIC(s1[i + 1])) {
            for (k = 1; k + s1[i - 1] <= s1[i + 1]; k++, j++)
                s2[j] = k + s1[i - 1];
            i++;
        } else
            s2[j++] = s1[i];
    s2[j] = '\0';
}

void itoa(int num, char buf[]) {
    int i, sign;

    i = 0;
    sign = num & (0x1 << (sizeof(int) * 8 - 1));
    if (sign) {
        buf[i++] = -(num % 10) + '0';
        num /= -10;
    }
    while (num > 0) {
        buf[i++] = num % 10 + '0';
        num /= 10;
    }
    if (sign)
        buf[i++] = '-';

    buf[i++] = '\0';
    reverse(buf);
}

void itob(unsigned int n, char s[], int b) {
    int i, temp;

    i = 0;
    while (n > 0) {
        temp = n % b;
        s[i++] = temp + ((temp <= 9) ? '0' : 'A' - 10);
        n /= b;
    }
    s[i] = '\0';
    reverse(s);
}

void itoa_w(unsigned int n, char s[], int width) {
    int i, temp;

    i = 0;
    while (n > 0) {
        temp = n % 10;
        s[i++] = temp + '0';
        n /= 10;
    }
    while (i < width)
        s[i++] = '0';
    s[i] = '\0';
    reverse(s);
}
