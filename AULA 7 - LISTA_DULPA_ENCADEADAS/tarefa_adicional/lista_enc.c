#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

#define DEBUG

struct listas_enc
{
    no_t *cabeca;   /*!< Referência da cabeça da lista encadeada: primeiro elemento. */
    no_t *cauda;    /*!< Referência da cauda da lista encadeada: último elemento. */
    int tamanho;    /*!< Tamanho atual da lista. */
};

/**
  * @brief  Cria uma nova lista encadeada vazia.
  * @param	Nenhum
  *
  * @retval lista_enc_t *: ponteiro (referência) da nova lista encadeada.
  */
lista_enc_t *criar_lista_enc (void)
{
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL)
    {
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}


/**
  * @brief  Obtém a referência do início (cabeça) da lista encadeada.
  * @param	lista: lista que se deseja obter o início.
  *
  * @retval no_t *: nó inicial (cabeça) da lista.
  */
no_t *obter_cabeca(lista_enc_t *lista)
{
    return lista->cabeca;
}

/**
  * @brief  Obtém a referência do fim (cauda) da lista encadeada.
  * @param	lista: lista que se deseja obter o fim.
  *
  * @retval no_t *: nó final (cauda) da lista.
  */
no_t *obter_cauda(lista_enc_t *lista)
{
    return lista->cauda;
}

/**
  * @brief  Adiciona um nó de lista no final.
  * @param	lista: lista encadeada que se deseja adicionar.
  *         elemento: nó que será adicionado na cauda.
  *
  * @retval Nenhum
      */
void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    no_t *prx = NULL;

    if (lista == NULL || elemento == NULL)
    {
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

#ifdef DEBUG
    printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
#endif // DEBUG

    //lista vazia
    if (tamanho(lista) == 0)
    {
#ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
#endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desligar_no(elemento);
    }
    else
    {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cauda da lista com novo elemento
        //ligar_nos(lista->cauda, elemento);


        lista->cauda = elemento;
        lista->tamanho++;
    }
}

void add_cabeca(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL)
    {
        fprintf(stderr,"add_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    //lista vazia
    if (lista_vazia(lista))
    {
#ifdef DEBUG
        printf("add_cabeca: add primeiro elemento: %p\n", elemento);
#endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;
        desligar_no(elemento);
    }
    else
    {
        // Remove qualquer ligacao antiga
        desligar_no(elemento);
        // Liga cabeça da lista como novo elemento
        //ligar_nos(elemento, lista->cabeca);

        elemento = xor(obter_atual(obter_cabeca(lista)),obter_atual(elemento));

        printf("obter atual da lista %s\n", obter_atual(obter_cabeca(elemento)));

        //lista->cabeca = xor(elemento, prx);

        lista->cabeca = elemento;
        lista->tamanho++;
    }
}

int tamanho(lista_enc_t *lista)
{
    return(lista->tamanho);
}

int lista_vazia(lista_enc_t *lista)
{
    return(!lista->tamanho);
}

void *remove_cabeca(lista_enc_t *lista)
{
    no_t *elemento, *prox;
    void *dado;

    if (lista == NULL)
    {
        fprintf(stderr,"remove_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    if(lista_vazia(lista))
    {
        fprintf(stderr,"remove_cabeca: lista_vazia");
        exit(EXIT_FAILURE);
    }
    elemento = obter_cabeca(lista);
    dado = obter_dado(elemento);
    prox = obter_proximo(elemento);

#ifdef DEBUG
    printf("remove_cabeca: removido elemento: %s\n", dado);
#endif // DEBUG

    lista->cabeca = prox;
    lista->tamanho--;
    free(elemento);
    return(dado);
}

void *remove_pos(lista_enc_t *lista, int pos)
{
    int i;
    no_t *elemento = obter_cabeca(lista);
    void* dado;

    if (lista == NULL)
    {
        fprintf(stderr,"remove_pos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    if(lista_vazia(lista))
    {
        fprintf(stderr,"remove_cabeca: lista_vazia");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<pos; i++)
        elemento = obter_proximo(elemento);

    ligar_nos(obter_anterior(elemento),obter_proximo(elemento));

    dado = obter_dado(elemento);

#ifdef DEBUG
    printf("remove_pos: removido elemento[%d]: %p\n",pos, dado);
#endif // DEBUG
    lista->tamanho--;
    free(elemento);
    return(dado);
}

void* remove_cauda(lista_enc_t *lista)
{
    no_t *elemento, *ant;
    void *dado;

    if (lista == NULL)
    {
        fprintf(stderr,"remove_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
    if(lista_vazia(lista))
    {
        fprintf(stderr,"remove_cauda: lista_vazia");
        exit(EXIT_FAILURE);
    }

    elemento = obter_cauda(lista);
    dado = obter_dado(elemento);

    if(obter_cauda(lista) == obter_cabeca(lista))
        desligar_no(elemento);
    else
    {
        ant = obter_anterior(elemento);
        desligar_no_prox(ant);
        lista->cauda = ant;
    }
#ifdef DEBUG
    printf("remove_cabeca: removido elemento: %s\n", dado);
#endif // DEBUG
    lista->tamanho--;
    free(elemento);
    return(dado);
}



void imprimi_lista(lista_enc_t* lista)
{
    no_t *meu_no = obter_cabeca(lista);
    no_t *anterior = NULL, *prx;

    prx = xor(obter_atual(meu_no), anterior);

    if (lista == NULL)
    {
        fprintf(stderr,"imprimi_lista: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    if(lista_vazia(lista))
    {
        fprintf(stderr,"imprimi_lista: lista vazia");
        exit(EXIT_FAILURE);
    }

    while(meu_no)
    {
        printf("Conteudo: %s\n", obter_dado(meu_no));
        prx = xor(meu_no, anterior);
        anterior = meu_no;
        meu_no = prx;
    }
}

void imprimi_lista_tras(lista_enc_t* lista)
{
    no_t *meu_no = obter_cauda(lista);

    if (lista == NULL)
    {
        fprintf(stderr,"imprimi_lista_tras: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    if(lista_vazia(lista))
    {
        fprintf(stderr,"imprimi_lista_tras: lista vazia");
        exit(EXIT_FAILURE);
    }

    while(meu_no)
    {
        printf("Conteudo: %s\n", obter_dado(meu_no));
        meu_no = obter_anterior(meu_no);
    }
}

