#include <stdio.h>
#define IN 1
#define OUT 0

main()
{
    int c, prev, q_count;
    int c_state, s_state, q_state;
    int double_quotes, single_quotes, parenthesis, braces, brackets, angle_brackets, comments;

    c_state = OUT;
    s_state = OUT;
    q_state = OUT;
    prev = -1;
    double_quotes = single_quotes = parenthesis = braces = brackets = angle_brackets = comments = 0;
    q_count = 0;

    while ((c = getchar()) != EOF)
    {
        if (prev != '\\' && c_state != IN && s_state != IN && q_state != IN)
        {
            switch (c)
            {
            case '"':
                s_state = IN;
                double_quotes++;
                break;
            case '\'':
                q_state = IN;
                single_quotes++;
                break;
            case '{':
                braces++;
                break;
            case '[':
                brackets++;
                break;
            case '(':
                parenthesis++;
                break;
            case '}':
                if (braces)
                    braces--;
                else
                {
                    braces = -1;
                    goto end;
                }
                break;
            case ']':
                if (brackets)
                    brackets--;
                else
                {
                    brackets = -1;
                    goto end;
                }
                break;
            case ')':
                if (parenthesis)
                    parenthesis--;
                else
                {
                    parenthesis = -1;
                    goto end;
                }
                break;
            case '*':
                if (prev == '/')
                {
                    c_state = IN;
                    comments++;
                }
                break;
            }
        }
        else if (c_state == OUT && s_state == IN && c == '"')
        {
            double_quotes--;
            s_state = OUT;
        }
        else if (q_state == IN && c == '\'')
        {
            s_state = OUT;
            if (q_count > 1)
                goto end;
            else
                single_quotes--;
        }
        else if (q_state == IN)
            q_count++;
        else if (c_state == IN && prev == '*' && c == '/')
        {
            c_state = OUT;
            if (comments)
                comments--;
            else
            {
                brackets = -1;
                goto end;
            }
        }
        prev = c;
    }
end:
    if (double_quotes % 2 != 0)
        printf("Unbalanced double quotes\n");
    if (single_quotes % 2 != 0)
        printf("Unbalanced single quotes\n");
    if (brackets)
        printf("Unbalanced brackets\n");
    if (braces)
        printf("Unbalanced braces\n");
    if (parenthesis)
        printf("Unbalanced parenthesis\n");
    if (comments)
        printf("Unbalanced comment delimiters\n");
}
