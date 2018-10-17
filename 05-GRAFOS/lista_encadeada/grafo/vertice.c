/*
 * vertice.c
 *
 *  Created on: Jul 5, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>

#include "vertice.h"
#include "../lista_enc/lista_enc.h"

struct vertices {
	int id;                /*!< Identificação numérica do vértice  */
	int dist;			   /*!< Distância entre o vertice inicial e o atual */
	int visitado;		   /*!< Verifica se o vertice já foi visitado */
	lista_enc_t *arestas;  /*!< Listas encadeada das arestas pertencentes ao vértice  */

	/* Informações para componentes conexos */
	int id_grupo;
	vertice_t* pai;

};

struct arestas {
	int peso;          /*!< Identificação numérica da aresta  */
	vertice_t *fonte;  /*!< Vértice fonte. Geralmente vértice pertencente a lista de arestas do vértice */
	vertice_t *dest;   /*!< Vértice destino */

	status_aresta_t status;     /*!< Estado de exportação. Utilizado na função de exportação para dot. */
};

/**
  * @brief  Cria uma novo vértice 
  * @param	id: Identificação numérica do vértice
  *
  * @retval vertice_t: ponteiro para um novo vértice
  */
vertice_t *cria_vertice(int id)
{
	vertice_t *p = NULL;

	p = malloc(sizeof(vertice_t));

	if (p == NULL) {
		perror("cria_vertice:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->arestas = cria_lista_enc();
	p->id_grupo = -1;
	p->pai = NULL;

	return p;
}

/**
  * @brief  Obtém o identificador numérico do vértice
  * @param	vertice: ponteiro do vértice
  *
  * @retval int: identificador numérico do vértice
  */
int vertice_get_id(vertice_t *vertice)
{
	if (vertice == NULL)
	{
		fprintf(stderr, "vertice_obter_id: vertice invalido!\n");
		exit(EXIT_FAILURE);
	}

	return vertice->id;
}
/**
  * @brief  Cria uma aresta entre dois vértices
  * @param	fonte: ponteiro do vértice fonte
  * @param	destino: ponteiro do vértice destino
  * @param  peso: peso da aresta
  *
  * @retval arestas_t: ponteiro da nova aresta criada
  */
arestas_t *cria_aresta(vertice_t *fonte, vertice_t *destino, int peso)
{
	arestas_t *p;

	p = (arestas_t*)malloc(sizeof(arestas_t));

	if (p == NULL) {
		perror("cria_aresta:");
		exit(EXIT_FAILURE);
	}

	p->peso = peso;
	p->fonte = fonte;
	p->dest = destino;

	return p;
}

/**
  * @brief  Adiciona uma nova aresta na lista de arestas de um vértice
  * @param	vertice: ponteiro do vértice
  * @param	aresta: ponteiro da aresta
  *
  * @retval Nenhum
  */
void adiciona_aresta(vertice_t *vertice, arestas_t *aresta)
{
	no_t *no;

	if (vertice == NULL || aresta == NULL)	{
		fprintf(stderr, "adiciona_aresta: dados invalidos\n");
		exit(EXIT_FAILURE);
	}

	no = cria_no(aresta);
	add_cauda(vertice->arestas, no);

}

/**
  * @brief  Obtém a lista encadadeada de arestas: útil para obter todos vértices adjacentes
  * @param	vertice: ponteiro do vértice
  *
  * @retval lista_enc_t: lista encadeada contendas as arestas
  */
lista_enc_t *vertice_get_arestas(vertice_t *vertice)
{
	if (vertice == NULL){
		fprintf(stderr, "vertice_get_arestas: vertice invalido\n");
		exit(EXIT_FAILURE);
	}

	return vertice->arestas;
}

/**
  * @brief  Obtém o peso se uma aresta
  * @param	aresta: ponteiro da aresta
  *
  * @retval int: peso numérico da aresta
  */
int aresta_get_peso (arestas_t *aresta) {
	if (aresta == NULL){
		fprintf(stderr, "aresta_get_peso: aresta invalido\n");
		exit(EXIT_FAILURE);
	}

	return aresta->peso;
}

/**
  * @brief  Obtém o vértice adjacente de um aresta
  * @param	aresta: ponteiro da aresta
  *
  * @retval vertice_t: vértice adjacente ou destino
  */
vertice_t *aresta_get_adjacente(arestas_t *aresta)
{
	if (aresta == NULL){
		fprintf(stderr, "aresta_get_adjacente: aresta invalido\n");
		exit(EXIT_FAILURE);
	}

	return aresta->dest;
}

/**
  * @brief  Retorna uma aresta se um vértice for adjacente a outro: busca linear na lista de arestas
  * @param	vertice: vértice de referência
  * @param  adjacente: vértice que se deseja verificar se é adjacente à referência
  *
  * @retval arestas_t: aresta adjacente. NULL se não for adjacente
  */
arestas_t *procurar_adjacente(vertice_t *vertice, vertice_t *adjacente)
{
	no_t *no;
	arestas_t *aresta;

	if (vertice == NULL){
		fprintf(stderr, "procurar_adjacente: aresta invalido\n");
		exit(EXIT_FAILURE);
	}

	no = obter_cabeca(vertice->arestas);

	while (no){

		aresta = obter_dado(no);

		if (aresta->dest == adjacente || aresta->fonte == adjacente)
			return aresta;

		no = obtem_proximo(no);
	}

	return NULL;
}

/**
  * @brief  Retorna o estado de exportação de uma aresta. Utilizada para geração do dot
  * @param	aresta: aresta em questão
  *
  * @retval status_aresta_t: estado atual: conforme status_aresta_t
  */
status_aresta_t aresta_get_status (arestas_t *aresta)
{
	if (aresta == NULL){
		fprintf(stderr, "aresta_get_status: aresta invalida\n");
		exit(EXIT_FAILURE);
	}

	return aresta->status;
}

/**
  * @brief  Altera o de exportação de uma aresta. Utilizada para geração do dot
  * @param	aresta: aresta em questão
  * @param  status: novo estado: conforme status_aresta_t
  *
  * @retval Nenhum
  */
void aresta_set_status(arestas_t *aresta, status_aresta_t status)
{
	if (aresta == NULL){
		fprintf(stderr, "aresta_set_status: aresta invalida\n");
		exit(EXIT_FAILURE);
	}

	aresta->status = status;
}

/**
  * @brief  Altera a propriedade grupo de um vértice
  * @param	vertice: vértice em questão
  * @param  grupo: novo grupo
  *
  * @retval Nenhum
  */
void vertice_set_grupo(vertice_t *vertice, int grupo) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_grupo: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->id_grupo = grupo;
}

/**
  * @brief  Obtém a propriedade grupo de um vértice
  * @param	vertice: vértice em questão
  *
  * @retval int: grupo da aresta
  */
int vertice_get_grupo(vertice_t *vertice) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_get_grupo: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->id_grupo;
}
/**
  * @brief  Altera a propriedade pai de um vértice
  * @param	vertice: vértice em questão
  * @param  pai: novo vértice adjacente e pai 
  *
  * @retval Nenhum
  */
void vertice_set_pai(vertice_t *vertice, vertice_t *pai) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_pai: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->pai = pai;
}

void vertice_set_dist(vertice_t *vertice, int dist){

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_dist: vertice invalido\n");
			exit(EXIT_FAILURE);
	}
	vertice->dist = dist;
}

int vertice_get_dist(vertice_t *vertice) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_get_dist: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->dist;
}

vertice_t* vertice_get_pai(vertice_t *vertice) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_get_pai: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->pai;
}

vertice_t* aresta_get_dest(arestas_t *aresta){
	return aresta->dest;
}

void vertice_set_visitado(vertice_t *v, int visitado){
	v->visitado = visitado;
}

int vertice_get_visitado(vertice_t *v){
	return(v->visitado);
}
