#include <stdlib.h>
#include <stdio.h>
#include "lista_enc.h"
#include "pilha.h"

struct pilhas {
    lista_enc_t *lista;
};


/**
  * @brief  Cria uma nova pilha
  * @param	Nenhum
  *
  * @retval pilha_t: ponteiro para uma nova pilha
  */
pilha_t * cria_pilha (void)
{
    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t));
    pilha->lista = criar_lista_enc();
    return pilha;
}

/**
  * @brief  Empilha um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da pilha
  * @param pilha: pilha criada que receberá o dado.
  *
  * @retval Nenhum
  */
void push(void *dado, pilha_t *pilha)
{
    no_t *elemento = criar_no((void*)(dado));
    add_cabeca(pilha->lista, elemento);
}

void* pop(pilha_t *pilha)
{
    //no_t *elemento = obter_cabeca(pilha->lista);
    void* dado = remove_cabeca(pilha->lista);
    return dado;

}

void  mostra(pilha_t *pilha)
{
    no_t *meu_no = obter_cabeca(pilha->lista);

    while(meu_no)
    {
        printf("Conteudo: %s\n", obter_dado(meu_no));
        meu_no = obter_proximo(meu_no);
    }
}


void*topo(pilha_t *pilha)
{
    no_t *meu_no = obter_cabeca(pilha->lista);
    return(obter_dado(meu_no));
}
int tamanho_pilha(pilha_t *pilha)
{
    return (tamanho(pilha->lista));
}

int vazia(pilha_t *pilha)
{
    return !tamanho(pilha->lista);
}

void free_pilha(pilha_t *pilha)
{
    if (tamanho(pilha->lista) == 0){
        free(pilha->lista);
        free(pilha);
    }
    else
        fprintf(stderr, "Erro: liberando pilha não vazia!");
}




