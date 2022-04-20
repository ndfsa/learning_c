#include "ch4utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNC 'f'
#define VAR 'v'
#define RETRIEVE 'r'

int getop(char[]);
void push(double);
double pop(void);
void clear_stack();
void parse_func(char[]);

double variables[28];

main() {
    /* Suppose that there will never be more than one character of pushback. Modify getch and
     * ungetcch accordingly.
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
        case RETRIEVE:
            push(s[0] == 63 ? variables[27] : variables[s[0] - 'a']);
            break;
        case VAR:
            push(s[0] - 'a');
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
            op = pop();
            variables[27] = op;
            printf("\t%.8g\n", op);
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
    else if (strindex(s, "STO") == 0) {
        int index = (int)pop();
        double val = pop();
        variables[index] = val;
    } else
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
    if (!isalnum(c) && c != '.' && c != '-' && c != '$')
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
    if (islower(c)) {
        s[i] = c;
        return VAR;
    }
    if (c == '$') {
        if (islower(s[0] = c = getch()) || c == '?')
            return RETRIEVE;
        else
            return c;
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

char buf = -1;

int getch(void) {
    int res = 0;
    if (buf != -1) {
        res = buf;
        buf = -1;
        return res;
    } else
        return getchar();
}

void ungetch(int c) { buf = c; }
