#include <stdio.h>
#include <string.h>

int setbits(int x, int p, int n, int y);
void itoa(int num, char buf[]);
void reverse(char s[]);

main() {
    /* printf("The result is: %d\n", setbits(90, 5, 4, 147)); */
    char res[25];
    int num = 2147483647;

    itoa(num, res);

    printf("%d = %s\n", num, res);
}

int setbits(int x, int p, int n, int y) {
    /* set the n bits in position p from x,
     * to the n bits in position p from y */
    int mask = ~(~0 << n) << (p + 1 - n);
    return x & ~mask | y & mask;
}

void itoa(int num, char buf[]) {
    int i = 0;
    int sign = num & 0x80000000;

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

void reverse(char s[]) {
    int i, j;
    char aux;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}
