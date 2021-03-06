#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
void clear_stack();

main() {
    /* Add commands to print the top element of the stack without popping, to duplicate it, and to
     * swap the top two elements. Add a command to clear the stack.
     * */
    int type;
    double op, op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
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
        case 'P':
            op = pop();
            printf("\ttop: %.8g\n", op);
            push(op);
            break;
        case 'W':
            op = pop();
            op2 = pop();
            push(op);
            push(op2);
            break;
        case 'Y':
            op = pop();
            push(op);
            push(op);
            break;
        case 'X':
            clear_stack();
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
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
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
