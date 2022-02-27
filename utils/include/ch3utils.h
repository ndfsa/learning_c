#define IS_ALPHANUMERIC(x)                                                                        \
    ((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))

int binsearch(int, int[], int);
void escape(char[], char[]);
void rescape(char[], char[]);
void expand(char[], char[]);
