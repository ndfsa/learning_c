#include "ch4utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNC 'f'

int getop(char[]);
void push(double);
double pop(void);
void clear_stack();
void parse_func(char[]);

main() {
    /* Add access to library functions like sin, exp and pow. See <math.h> in Apendix B, Section 4.
     * */
    int type;
    double op, op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case FUNC:
            parse_func(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

void parse_func(char s[]) {
    double op, op2;
    if (strindex(s, "SIN") == 0)
        push(sin(pop()));
    else if (strindex(s, "COS") == 0)
        push(cos(pop()));
    else if (strindex(s, "TAN") == 0)
        push(tan(pop()));
    else if (strindex(s, "ASIN") == 0)
        push(asin(pop()));
    else if (strindex(s, "ACOS") == 0)
        push(acos(pop()));
    else if (strindex(s, "ATAN") == 0)
        push(atan(pop()));
    else if (strindex(s, "SINH") == 0)
        push(sinh(pop()));
    else if (strindex(s, "COSH") == 0)
        push(cosh(pop()));
    else if (strindex(s, "TANH") == 0)
        push(tanh(pop()));
    else if (strindex(s, "EXP") == 0)
        push(exp(pop()));
    else if (strindex(s, "LOG") == 0)
        push(log(pop()));
    else if (strindex(s, "POW") == 0) {
        op = pop();
        push(pow(pop(), op));
    } else if (strindex(s, "PRT") == 0) {
        op = pop();
        printf("\ttop: %.8g\n", op);
        push(op);
    } else if (strindex(s, "SWP") == 0) {
        op = pop();
        op2 = pop();
        push(op);
        push(op2);
    } else if (strindex(s, "DUP") == 0) {
        op = pop();
        push(op);
        push(op);
    } else if (strindex(s, "CLR") == 0)
        clear_stack();
    else
        printf("error: unknown function %s\n", s);
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear_stack() {
    int i;
    for (i = 0; i < MAXVAL; ++i) {
        val[i] = 0.0;
    }
    sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isalnum(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (isupper(c)) {
        while (isupper(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return FUNC;
    }
    if (c == '-')
        s[++i] = c = getch();
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (i > 0 && s[i - 1] == '-')
        return '-';
    else
        return NUMBER;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
