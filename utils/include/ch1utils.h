#ifndef CH1UTILS_H
#define CH1UTILS_H

#define IS_BLANK(x) (x == ' ' || x == '\t')

/* sizes for histograms */
#define WIDTH 50.0
#define HEIGHT 30

int counter_max(int[], int);
void histogram(int[], int);
void vhistogram(int[], int);
int getline(char[], int);
void copy(char[], char[]);
void clear_buffer(char *, int);
void reverse(char[]);

#endif
