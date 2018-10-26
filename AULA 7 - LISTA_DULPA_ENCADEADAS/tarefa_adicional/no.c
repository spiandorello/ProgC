#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <stdbool.h>

#include "no.h"

struct nos{
    void* dados;    /*!< Referência do dado respectiva ao nó da lista encadeada. */
    no_t *nox;
};

/**
  * @brief  Cria um novo nó de lista encadeada.
  * @param	dado: ponteiro genérico para qualquer tipo de dado.
  *
  * @retval no_t: ponteiro do tipo nó contendo a referência do dado.
  */
no_t *criar_no(void *dado)
{
    no_t *p = malloc(sizeof(no_t));

    if (p == NULL){
        perror("cria_no:");
        exit(EXIT_FAILURE);
    }
    p->dados = dado;
    p->nox = NULL;
    return p;
}

/**
  * @brief  Faz o encadeamento entre dois nós de encadeados.
  * @param	fonte: ponteiro da fonte entre a ligação.
  *         destino: ponteiro do destino entre a ligação.
  *
  * @retval Nenhum.
  */
void ligar_nos (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

}

/**
  * @brief  Remove encadeamento um nó encadeado.
  * @param	no: nó de lista que se deseja remover ligação.
  *
  * @retval Nenhum.
  */
void desligar_no (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"desliga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    no->nox = NULL;
}

/**
  * @brief  Obtém a referência do dado pertencente ao nó de lista encadeada.
  * @param	no: nó de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo nó encadeado.
  */
void *obter_dado (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    return no->dados;
}

/**
  * @brief  Obtém a próxima referência encadeada.
  * @param	no: nó de lista que se deseja obter o próximo elemento.
  *
  * @retval no_t *: ponteiro do próximo elemento da lista. NULL se final de lista.
  */
no_t *obter_proximo (no_t *no)
{
    no_t *anterior = NULL;
    if (no == NULL) {
        fprintf(stderr,"obter_proximo: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return xor(no, anterior);

}

/**
  * @brief  Obtém a próxima referência encadeada.
  * @param	no: nó de lista que se deseja obter o elemento anterior.
  *
  * @retval no_t *: ponteiro do elemento anterior da lista. NULL se inicio de lista.
  */
no_t *obter_anterior (no_t *no)
{
    if(no == NULL)
    {
        fprintf(stderr, "obter_anterior: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
//    return no->anterior;
}

no_t *obter_atual(no_t *no)
{
    if(no == NULL)
    {
        fprintf(stderr, "obter_anterior: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    return(no->nox);
}

void desligar_no_prox(no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"desliga_no_prox: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    no->nox = NULL;
}

no_t* xor(no_t *a, no_t *b){
    return (no_t*) ((uintptr_t) a ^ (uintptr_t) b);
}
