/*
 ============================================================================
 Name        : Arvores.c
 Author      : Eduardo
 Version     :
 Copyright   : Your copyright notice
 Description : Árvores binárias in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore/arvore.h"
#include "fila/fila.h"

int main(void) {

	arvore_t *arvore = cria_arvore(1);
	fila_t *fila = cria_fila();
	vertice_t *vertice;
	int id;

	vertice = arvore_adicionar_vertice_id(arvore, 1);
	enqueue(vertice, fila);

	vertice = arvore_adicionar_vertice_id(arvore, 2);
	enqueue(vertice, fila);

	vertice = arvore_adicionar_vertice_id(arvore, 3);
	enqueue(vertice, fila);

	vertice = arvore_adicionar_vertice_id(arvore, 4);
	enqueue(vertice, fila);

	while (!fila_vazia(fila))	{
		vertice = dequeue(fila);
		id = vertice_get_id(vertice);

		switch(id){
		case 1:
			arvore_set_raiz(arvore, vertice);
			arvore_adiciona_filhos(arvore, vertice, 2, 3);
			break;
		case 2:
			arvore_adiciona_filhos(arvore, vertice, 4, -1);
			break;

		default:
			arvore_adiciona_filhos(arvore, vertice, -1,-1);
			break;
		}
	}

	vertice = arvore_procura_vertice(arvore, 1);
	//exibir_pre_ordem(vertice);
	//exibir_pos_ordem(vertice);
	exibir_em_ordem(vertice);

	libera_fila(fila);
	libera_arvore(arvore);
	return(0);
}
