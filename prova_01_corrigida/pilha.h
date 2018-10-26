#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilhas pilha_t;

/**
  * @brief  Cria uma nova pilha com TAMANHO_DADOS_PILHA inteiros
  * @param	tamanho_pilha: tamanho da pilha que se criar
  *
  * @retval pilha_t: ponteiro para uma nova pilha
  */
pilha_t * cria_pilha (int tamanho_pilha);

/**
  * @brief Empilha um novo dado.
  * @param dado: inteiro a ser adicionado no topo da pilha
  * @param pilha: pilha criada que receberá o dado.
  *
  * @retval Nenhum
  */
void push(float dado, pilha_t *pilha);

/**
  * @brief Desempilha um dado.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval float: valor do último dado empilhado.
  */
float pop(pilha_t *pilha);


/**
  * @brief Imprime todos os dados da pilha. Não são retirados.
  * @param pilha: pilha válida criada.
  *
  * @retval Nenhum.
  */
void imprime_pilha(pilha_t *pilha);

/**
  * @brief Verifica se a pilha está vazia.
  * @param pilha: uma pilha válida criada.
  *
  * @retval int: 0 se pilha não estiver vazia. > 0 se conter alum dado.
  */
int pilha_vazia(pilha_t *pilha);

/**
  * @brief Libera os dados alocados pela pilha.
  * @param pilha: uma pilha válida criada.
  *
  * @retval Nenhum.
  */
void libera_pilha(pilha_t *pilha);

int pilha_tamanho(pilha_t *pilha);

#endif // PILHA_H_INCLUDED
