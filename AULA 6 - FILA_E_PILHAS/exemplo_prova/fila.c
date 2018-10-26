#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "pilha.h"
//#define DEBUG

struct filas {
    pilha_t *pilha_1;
    pilha_t *pilha_2;
    int tamanho;
};

/**
  * @brief  Cria uma nova fila de números inteiros
  * @param	tamanho: tamanho da fila desejada
  *
  * @retval fila_t: ponteiro para uma nova fila
  */
fila_t* cria_fila(void)
{
    fila_t *p = NULL;
    //aloca memória
    p = (fila_t*)malloc(sizeof(fila_t));

    p->pilha_1 = cria_pilha();
    p->pilha_2 = cria_pilha();
    p->tamanho = 0;
    return p;
}

/**
  * @brief  Libera os dados dinâmicos da fila
  * @param	fila: fila que será liberada
  *
  * @retval Nenhum
  */
void libera_fila(fila_t* fila)
{

}

void enqueue(int dado, fila_t *fila)
{
    push(dado,fila->pilha_1);
    fila->tamanho++;
}

int dequeue(fila_t* fila)
{
    int x;
    while(fila->tamanho-- > 0)
    {
        x = pop(fila->pilha_1);
        push(x,fila->pilha_2);
    }

    return(pop(fila->pilha_2));
}
