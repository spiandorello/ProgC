#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    fila_t *fila;
    char texto[][50] = {"Juca", "Zeca", "Zeeeh"};

    fila = cria_fila();
    enqueue(texto[0],fila);
    enqueue(texto[1],fila);
    enqueue(texto[2],fila);

    while (!vazia(fila))
        printf("%s\n", dequeue(fila));

    libera_fila(fila);
    return 0;
}
