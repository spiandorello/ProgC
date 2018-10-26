#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include "no.h"

typedef struct listas_enc lista_enc_t;

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc(void);

/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: nó que será adicionado na cauda.
  *
  * @retval Nenhum
  */
void add_cauda(lista_enc_t *lista, no_t* elemento);

/**
  * @brief  Adiciona um nó de lista no inicio.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: nó que será adicionado na inicio.
  *
  * @retval Nenhum
  */
void add_cabeca(lista_enc_t *lista, no_t* elemento);


/**
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista);

/**
  * @brief  Obtém o tamanho da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval int: tamanho da lista.
  */

int tamanho(lista_enc_t *lista);



/**
  * @brief  Verifica se a lista está vazia.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval int: retorna "1' se a lista está vazia;
  */

int lista_vazia(lista_enc_t *lista);


/**
  * @brief  Remove a cabeça da lista e libera o nó antigo.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval void*: dado que estava contido no da cabeça.
  */


void *remove_cabeca(lista_enc_t *lista);


#endif // LISTA_ENC_H_INCLUDED
