#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

struct pilhas {
    int topo;                       /*!< Índice do vetor que representa o topo da fila */
    int* data;                      /*!< Vetor que manterá os dados. */
    int* dois_data;                 /*!< Dobro do vetor de dados. */
    int tamanho;                    /*!< Tamanho do vetor.*/
};


/**
  * @brief  Cria uma nova pilha com TAMANHO_DADOS_PILHA inteiros
  * @param	Nenhum
  *
  * @retval pilha_t: ponteiro para uma nova pilha
  */
pilha_t * cria_pilha (int tamanho)
{
    pilha_t *pilha;

    pilha= (pilha_t*) malloc(sizeof(pilha_t));
    if(pilha==NULL){
        fprintf(stderr,"Erro ao alocar memória:");
        exit(-1);
    }

    pilha->data= (int*) malloc(sizeof(int)*tamanho);
    if(pilha->data==NULL){
        fprintf(stderr,"Erro ao alocar memória:");
        exit(-1);
    }

    pilha->topo = 0;
    pilha->tamanho=tamanho;

    return pilha;
}


/**
  * @brief  Empilha um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da pilha
  * @param pilha: pilha criada que receberá o dado.
  *
  * @retval Nenhum
  */
void push(int dado, pilha_t *pilha)
{

    if ((pilha->topo) > (pilha->tamanho)) {
        fprintf(stderr, "Tamanho maximo da pilha atingido!\n");
        exit(EXIT_FAILURE);
    }

    pilha->data[pilha->topo] = dado;
    pilha->topo++;

    if((pilha->topo)==(pilha->tamanho)){
        pilha->data = (int*) realloc((pilha->data),2 * (pilha->tamanho));
        if(pilha->data==NULL){
            fprintf(stderr,"Erro ao alocar memória:");
            exit(-1);
        }
        else{
            pilha->tamanho=(pilha->tamanho)*2;
            printf("\n\nNovo tamanho %d\n", pilha->tamanho);
        }

    }
}

/**
  * @brief Desempilha um inteiro.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval int: valor inteiro do último dado empilhado.
  */
int pop(pilha_t *pilha)
{
    int topo = pilha->topo;

    if (topo < 0 || topo > TAMANHO_DADOS_PILHA){
        fprintf(stderr, "Pilha corrompida!\n");
        exit(EXIT_FAILURE);
    }

    if(pilha->topo < (pilha->tamanho)/2){
        pilha->data= (int*) realloc(pilha->data, (pilha->tamanho)/2);
        if(pilha->data==NULL)
            fprintf(stderr,"Erro ao alocar memória");
        else{
            pilha->tamanho=(pilha->tamanho)/2;
            printf("\n\nNovo tamanho %d\n", pilha->tamanho);
        }
    }

    if (pilha->topo==0) {
        fprintf(stderr, "pop() em pilha vazia!\n");
        return 0;
    }

    pilha->topo--;
    return pilha->data[topo - 1];
}
