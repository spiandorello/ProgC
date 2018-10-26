#include <stdio.h>
#include <stdlib.h>

struct _mat {
    int *data;
    int col;
    int row;
};
int main()
{
    typedef struct _mat mat;

    printf("Hello world!\n");
    return 0;
}
