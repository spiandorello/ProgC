#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define TAMANHO_DADOS_PILHA 100

typedef struct pilhas pilha_t;

/**
  * @brief  Cria uma nova pilha com TAMANHO_DADOS_PILHA inteiros
  * @param	Nenhum
  *
  * @retval pilha_t: ponteiro para uma nova pilha
  */
pilha_t * cria_pilha (void);

/**
  * @brief  Empilha um novo inteiro.
  * @param dado: qualquer tipo
  * @param pilha: pilha criada que receberá o dado.
  *
  * @retval Nenhum
  */
void push(void * dado, pilha_t *pilha);

/**
  * @brief Desempilha um inteiro.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval : valor do último dado empilhado.
  */
void *pop(pilha_t *pilha);

void  mostra(pilha_t *pilha);

void *topo(pilha_t *pilha);

int tamanho_pilha(pilha_t *pilha);

int vazia(pilha_t *pilha);

void free_pilha(pilha_t *pilha);


#endif // PILHA_H_INCLUDED
