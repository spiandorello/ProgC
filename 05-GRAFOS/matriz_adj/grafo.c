/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"
#include "fila/fila.h"
#include "pilha/pilha.h"

struct vertices {
	int id;         /*!< Identificação numérica do vértice  */
    int pai;
    int dist;
	int visitado;
    /* Mais informações, se necessário */
};

struct arestas {
	int adj;        /*!< Valor booleando. Verdadeiro representa uma adjacência entre dois vértices  */
	
    /* Mais informações, se necessário */
};

struct grafos{
	int n_vertices;        /*!< Número de vértices do grafo  */
	vertice_t *vertices;   /*!< Vetor de ponteiros: conjunto V */
	aresta_t **matriz_adj;	/* Matriz de adjacência: conjunto E */
};

/**
  * @brief  Cria uma novo grafo estático
  * @param	vertices: quantidade de vértices
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *cria_grafo(int vertices)
{
	int i;
	aresta_t **matriz_adj;
	/* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda número total de vértices */
	g->n_vertices = vertices;
    /* Aloca vértices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de vértices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));

    /* Aloca 1a dimensão da matriz de adjacência */
	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	 /* Aloca 2a dimensão da matriz de adjacência */
	for ( i = 0; i < vertices; i++ )
	{
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

/**
  * @brief  Libera a memória utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
void libera_grafo (grafo_t *g){
	int i;

	if (g == NULL){
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

/**
  * @brief  Cria adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for criada
  */
int cria_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

/**
  * @brief  Remove adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for removida
  */
int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

/**
  * @brief  Retorna adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se u for adjacente a v
  */
int adjacente(grafo_t *g, int u, int v){

	if (u > MAX_VERTICES || v > MAX_VERTICES)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}

void bfs(grafo_t *g, int inicial){

	fila_t *fila = cria_fila(g->n_vertices);
	int i, u;

	for(i = 0; i< g->n_vertices; i++){
		vertice_set_dist(g,i,INFINITO);
		vertice_set_pai(g, i, 0);
	}

	vertice_set_dist(g,inicial, 0);
	enqueue(inicial, fila);

	while(!fila_vazia(fila)){
			u = dequeue(fila);

			for(i=0; i < g->n_vertices; i++)
			{
				if(adjacente(g, u, i)){
					if(vertice_get_dist(g,i) == INFINITO){
						vertice_set_dist(g,i, vertice_get_dist(g,u) + 1);
						vertice_set_pai(g,i,u);
						enqueue(i, fila);
					}
					printf("pai: %d -----> vertice: %d ----> dist: %d\n",vertice_get_pai(g, i), i, vertice_get_dist(g,i));
				}

			}
		}
		libera_fila(fila);
}

void dfs(grafo_t *g, int inicial){

	pilha_t *pilha = cria_pilha();
	int i;

	for(i=0; i < g->n_vertices; i++)
		vertice_set_visitado(g, i, FALSE);

	push(inicial, pilha);

	while(!pilha_vazia(pilha))
	{
		int u = pop(pilha);
		printf("%d\n", u);

		if((vertice_visitado(g,u)) == FALSE){
			vertice_set_visitado(g,u,TRUE);

			for(i=0; i < g->n_vertices; i++)
			{
				if(adjacente(g,u,i))
					push(i, pilha);
			}
		}
	}
}

void vertice_set_dist(grafo_t *g, int i, int dist){
	g->vertices[i].dist = dist;
}

void vertice_set_pai(grafo_t *g, int i, int pai){
	g->vertices[i].pai = pai;
}

vertice_t obter_vertice(grafo_t *g, int u){

	return(g->vertices[u]);
}

int vertice_get_id(grafo_t *g, int i){

	return(g->vertices[i].id);
}

int vertice_get_dist(grafo_t *g, int i){

	return(g->vertices[i].dist);
}

int vertice_get_pai(grafo_t *g, int i){
	return(g->vertices[i].pai);
}

int vertice_visitado(grafo_t *g, int i){
	return(g->vertices[i].visitado);
}

void vertice_set_visitado(grafo_t *g, int i, int visit){
	g->vertices[i].visitado = visit;
}
