#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "lista_enc.h"

struct filas {
    lista_enc_t *lista;
};

/**
  * @brief  Cria uma nova fila com lista encadeada
  * @param	Nenhum.
  *
  * @retval fila_t: ponteiro para uma nova fila
  */
fila_t* cria_fila()
{
    fila_t *fila = malloc(sizeof(fila_t));
    fila->lista = criar_lista_enc();
    return(fila);
}

/**
  * @brief  Libera os dados dinâmicos da fila
  * @param	fila: fila que será liberada
  *
  * @retval Nenhum
  */
void libera_fila(fila_t *fila)
{
    if (tamanho(fila->lista) == 0)
    {
        free(fila->lista);
        free(fila);
    }
    else
        fprintf(stderr, "Erro: liberando pilha não vazia!");
}

/**
  * @brief Enfileira um novo elemento.
  * @param dado: qualquer tipo
  * @param fila: fila criada que receberá o dado.
  *
  * @retval Nenhum
  */
void enqueue(void *dado, fila_t* fila)
{
    no_t *elemento = criar_no(dado);
    add_cauda(fila->lista, elemento);
}

/**
  * @brief Desenfileira um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da fila
  * @param fila: fila criada que receberá o dado.
  *
  * @retval Nenhum
  */
void* dequeue(fila_t* fila)
{
    void *dado = remove_cabeca(fila->lista);
    return(dado);
}

int vazia(fila_t *fila)
{
    return !tamanho(fila->lista);
}
