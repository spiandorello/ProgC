#include "sort.h"

#include <stdio.h>
#include <stdlib.h>

void bubble(int *v, int n){

	int i, j;

	for(i = n; i > 1; i--)
		for(j = 0; j < i -1; j++)
			if(v[j] > v[j + 1])
				swap(&v[j], &v[j + 1]);
}

void qs(int *v, int esq, int dir){

	int p = 0;

	if(esq < dir){
		p = particiona(v, esq, dir);
		qs(v, esq, p);
		qs(v, p + 1, dir);
	}
}

void insertsort_direta(int *v, int n){

	int i, j;

	for(i = 1; i < n; i++)
		for(j = i; j > 0 && v[j-1] > v[j]; j--)
			swap(&v[j], &v[j - 1]);
}


void insertsort_binaria(int *v, int n){

	int i, temp = 0, meio;
	int esq, dir, j;

	for(i = 1; i < n; i++){

		temp = v[i];
		esq = 0;
		dir = i;

		while(esq < dir){

			meio = (esq + dir)/2;

			(temp >= v[meio]) ? (esq = meio + 1) : (dir = meio);
		}

		for(j = i; j > esq; j--)
			swap(&v[j-1], &j);
	}
}

void merge_sort(int *v, int esq, int dir){

	int meio = 0;

	if(esq < dir){

		meio = (esq + dir) / 2;
		merge_sort(v, esq, meio);
		merge_sort(v, meio + 1, dir);

		funde(v, esq, meio, dir);
	}
}

void swap(int *a, int *b){

	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

int mediana_de_tres(int *v, int esq, int dir){

	int med = (esq + dir)/2;

	if(v[dir] < v[esq])
		swap(&v[esq], &v[dir]);

	if(v[med] < v[esq])
		swap(&v[med], &v[esq]);

	if(v[dir] < v[med])
		swap(&v[dir], &v[med]);

	return(med);
}

int particiona(int *v, int esq, int dir){

	int i, j;
	int med  = mediana_de_tres(v, esq, dir);
	int pivo = v[med];


	i = esq -1;
	j = dir +1;

	while(1){

		do{
			i++;
		} while(v[i] < pivo);

		do{
			j--;
		} while(v[j] > pivo);

		if (i >= j)
			return j;

		swap(&v[i], &v[j]);
	}
}

void funde(int *v, int esq, int meio, int dir){

	int i, j, k;
	int *temp;

	temp = (int *) malloc(sizeof(int) * SIZE);

	if(temp == NULL){
		perror("Erro ao alocar memoria: ");
		exit(EXIT_FAILURE);
	}

	i = dir;
	j = esq;
	k = meio + 1;

	while(j <= meio && k <= dir)
		(v[j] < v[k]) ? (temp[i++] = v[j++]) : (temp[i++] = v[k ++]);

	while(j <= meio)
		temp[i++] = v[j++];

	for(i = esq; i < k; i++)
		v[i] = temp[i];

}



