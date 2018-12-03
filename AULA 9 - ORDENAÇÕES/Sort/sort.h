/*
 * bublle.h
 *
 *  Created on: 22 de nov de 2018
 *      Author: eduardo
 */

#ifndef SORT_H_
#define SORT_H_

#define SIZE 100000


/* Ordenações */
/* n --> tamanho do vetor */

void bubble(int *v, int n);
void qs(int *v, int esq, int dir);

void insertsort_direta(int *v, int n);
void insertsort_binaria(int *v, int n);


void merge_sort_imp(int *v, int *temp, int esq, int dir);
void merge_sort(int *v, int n);

void select_sort(int *v, int n);

/* Funções Auxiliares */

void swap(int *a, int *b);
int mediana_de_tres(int *v, int esq, int dir);
int particiona(int *v, int esq, int dir);
void funde(int *v, int *temp, int esq, int meio, int dir);
void heap_sort(int *vet, int n);
void build_heap(int *vet, int i, int k);


#endif /* SORT_H_ */
