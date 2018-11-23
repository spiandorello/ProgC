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


void merge_sort(int *v, int esq, int dir);

/* Funções Auxiliares */

void swap(int *a, int *b);
int mediana_de_tres(int *v, int esq, int dir);
int particiona(int *v, int esq, int dir);
void funde(int *v, int esq, int meio, int dir);


#endif /* SORT_H_ */
