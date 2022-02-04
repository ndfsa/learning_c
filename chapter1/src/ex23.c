#include <stdio.h>
#define IN 1
#define OUT 0

main()
{
    /* Write a prigram to remove all comments from a C program. Don't forget to handle quoted
     * strings and character constants properly. C comments do not nest.
     * */
    int c, prev, s_state, c_state;
    prev = -1;
    s_state = OUT;
    c_state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (s_state == OUT && c == '"')
        {
            if (prev != '\'')
                s_state = IN;
            putchar(c);
        }
        else if (c == '"')
        {
            putchar(c);
            s_state = OUT;
        }
        else if (s_state == OUT)
        {
            if (c_state == OUT)
                switch (c)
                {
                case '/':
                    break;
                case '*':
                    if (prev == '/')
                        c_state = IN;
                    else
                        putchar(c);
                    break;
                default:
                    if (prev == '/')
                        putchar(prev);
                    putchar(c);
                    break;
                }
            else if (c == '/' && prev == '*')
            {
                c_state = OUT;
                continue;
            }
        }
        else
        {
            putchar(c);
        }
        prev = c;
    }
}
