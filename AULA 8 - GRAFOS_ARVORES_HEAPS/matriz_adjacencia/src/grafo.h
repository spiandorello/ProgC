/*
 * grafo.h
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#define TRUE 1
#define FALSE 0
#define INFINITO -1
#define NINGUEM  -2150000
#define MAX_VERTICES 100
typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);
void bfs(grafo_t *g, int inicial);
void dfs(grafo_t *g, int inicial);
void vertice_set_dist(grafo_t *g, int i, int dist);
void vertice_set_pai(grafo_t *g, int i, int pai);
vertice_t obter_vertice(grafo_t *g, int u);
int vertice_get_id(grafo_t *g, int i);
int vertice_get_dist(grafo_t *g, int i);
int vertice_get_pai(grafo_t *g, int i);
int vertice_visitado(grafo_t *g, int i);
void vertice_set_visitado(grafo_t *g, int i, int visit);
#endif /* GRAFO_H_ */
