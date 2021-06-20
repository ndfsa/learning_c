#include <stdio.h>
#define MAXLINE 1000

int getline(char line[]);
void copy(char from[], char to[]);

main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line)) != 0)
        if (len > max)
        {
            max = len;
            copy(line, longest);
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getline(char line[])
{
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char from[], char to[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
