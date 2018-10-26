/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void) {


	//int i,j;
	grafo_t *g;

    /* Cria grafo com 20 vértices */
	g = cria_grafo(20);

	/*    Adicionar arestas    */

	cria_adjacencia(g,1,2);
	cria_adjacencia(g,1,3);
	cria_adjacencia(g,2,4);
	cria_adjacencia(g,2,5);
	cria_adjacencia(g,3,5);
	cria_adjacencia(g,3,7);
	cria_adjacencia(g,3,8);
	cria_adjacencia(g,5,6);

	bfs(g,1);
	//dfs(g,1);

	/* Imprime matriz */
	/*
	for (i=0; i < 20; i++){
		for (j=0; j < 20; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}*/

	libera_grafo(g);

	return EXIT_SUCCESS;
}
