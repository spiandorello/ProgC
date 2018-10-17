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
    p->cauda = 0;
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
    int fim = fila->cauda++;

    if(fila->tamanho > fila->tamanho_max - 1){
        fprintf(stderr, "Tamanho maximo da fila atingido!\n");
        exit(EXIT_FAILURE);
    }

    fila->dados[fim] = dado;
    fila->tamanho++;
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
    if (fila->tamanho == 0)
    {
        fprintf(stderr,"dequeue em fila vazia");
        exit(EXIT_FAILURE);
    }
    fila->tamanho--;
    return(fila->dados[topo]);
    free(fila->dados);
}

int fila_vazia(fila_t *fila){

	return(!fila->tamanho);
}
