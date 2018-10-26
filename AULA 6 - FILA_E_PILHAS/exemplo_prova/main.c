#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    fila_t *fila;

    fila = cria_fila();
    enqueue(10,fila);
    enqueue(100, fila);
    enqueue(1000, fila);

    printf("%d\n",dequeue(fila));
    printf("%d\n",dequeue(fila));
    printf("%d\n",dequeue(fila));

    return 0;
}
