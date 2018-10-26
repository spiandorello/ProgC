#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

struct pilhas {
    int topo;   		/*!< Índice do vetor que representa o topo da fila */
    int tamanho_max;	/*!< Tamanho máximo da pilha: valor passado na criação da estrutura */
    float *dados; 		/*!< Vetor que manterá os dados. */
};


/**
  * @brief  Cria uma nova pilha com TAMANHO_DADOS_PILHA inteiros
  * @param	tamanho_pilha: tamanho da pilha que se criar
  *
  * @retval pilha_t: ponteiro para uma nova pilha
  */
pilha_t * cria_pilha (int tamanho_pilha)
{
    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t));

    if (!pilha){
    	perror("cria pilha");
    	exit(EXIT_FAILURE);
    }

    pilha->topo = 0;
    pilha->tamanho_max = tamanho_pilha;
    pilha->dados = malloc(tamanho_pilha * sizeof(float));

    if (!pilha->dados){
    	perror("cria pilha");
    	exit(EXIT_FAILURE);
    }

    return pilha;
}

/**
  * @brief Empilha um novo dado.
  * @param dado: inteiro a ser adicionado no topo da pilha
  * @param pilha: pilha criada que receberá o dado.
  *
  * @retval Nenhum
  */
void push(float dado, pilha_t *pilha)
{
    int topo = pilha->topo;

    if (topo > pilha->tamanho_max) {
        fprintf(stderr, "Tamanho maximo da pilha atingido!\n");
        exit(EXIT_FAILURE);
    }

    pilha->dados[topo] = dado;
    pilha->topo++;
}

/**
  * @brief Desempilha um dado.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval float: valor do último dado empilhado.
  */
float pop(pilha_t *pilha)
{
    int topo = pilha->topo;

    if (topo < 0 || topo > pilha->tamanho_max){
        fprintf(stderr, "Pilha corrompida!\n");
        exit(EXIT_FAILURE);
    }

    if (topo == 0) {
        fprintf(stderr, "pop() em pilha vazia!\n");
        return 0;
    }

    pilha->topo--;
    return pilha->dados[topo - 1];
}


/**
  * @brief Imprime todos os dados da pilha. Não são retirados.
  * @param pilha: pilha válida criada.
  *
  * @retval Nenhum.
  */
void imprime_pilha(pilha_t *pilha){

	int i;

	for (i=0; i < pilha->topo; i++)
		printf("%f\n", pilha->dados[i]);
}

/**
  * @brief Verifica se a pilha está vazia.
  * @param pilha: uma pilha válida criada.
  *
  * @retval int: 0 se pilha não estiver vazia. > 0 se conter alum dado.
  */
int pilha_vazia(pilha_t *pilha){
	return !pilha->topo;
}

/**
  * @brief Libera os dados alocados pela pilha.
  * @param pilha: uma pilha válida criada.
  *
  * @retval Nenhum.
  */
void libera_pilha(pilha_t *pilha){
	free(pilha->dados);
	free(pilha);
}

int pilha_tamanho(pilha_t *pilha){
    return(pilha->topo);
}
