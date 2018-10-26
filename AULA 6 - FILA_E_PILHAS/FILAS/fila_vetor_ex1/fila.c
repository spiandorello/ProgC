#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

struct filas {
    int cabeca;     /*!< Índice do vetor que representa a cabeça da fila. */
    int cauda;      /*!< Índice do vetor que representa a cauda da fila. */
    int tamanho;    /*!< Tamanho atual da fila. */
    int tamanho_max; /*!< Tamanho máximo: utilizado pelo alocador dinâmico. */
    int *dados;     /*!< Vetor alocado dinamicamente que mantém os dados da fila. */
};

/**
  * @brief  Cria uma nova fila de números inteiros
  * @param	tamanho: tamanho da fila desejada
  *
  * @retval fila_t: ponteiro para uma nova fila
  */
fila_t* cria_fila(int tamanho)
{
    fila_t *p = NULL;

    //aloca memória
    p = (fila_t*)malloc(sizeof(fila_t));

    //variaveis de controle
    p->cabeca = 0;
    p->cauda =  0;
    p->tamanho = 0;
    p->tamanho_max = tamanho;

    p->dados = (int*) malloc(sizeof(int) * tamanho);

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
    free(fila->dados);
    free(fila);
}

/**
  * @brief Enfileira um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da fila
  * @param fila: fila criada que receberá o dado.
  *
  * @retval Nenhum
  */
void enqueue(int dado, fila_t* fila)
{
    int fim = fila->cauda;
    int tamanho_max = fila->tamanho_max;

    if (fila->tamanho == tamanho_max - 1)
    {
        tamanho_max *= 2;
        printf("atualizando tamanho: %d\n", fila->tamanho);
        fila->dados = realloc(fila->dados, sizeof(int) * tamanho_max);
        fila->tamanho_max = tamanho_max;
    }
    fila->dados[fim] = dado;
    fila->tamanho++;
    fila->cauda++;
}


/**
  * @brief Empilha um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da fila
  * @param fila: fila criada que receberá o dado.
  *
  * @retval Nenhum
  */
int dequeue(fila_t* fila)
{
    int topo = fila->cabeca++;
    int tamanho = fila->tamanho_max;

    if (topo == fila->cauda) {
        fprintf(stderr, "dequeue em fila vazia!\n");
        return 0;
    }

    if (fila->tamanho == (tamanho/2))
    {
        fila->dados = realloc(fila->dados, sizeof(int) * tamanho);
        printf("atualizando tamanho: %d\n", fila->tamanho);
        fila->tamanho_max = tamanho;
    }

    fila->tamanho--;
    return (fila->dados[topo]);
}
