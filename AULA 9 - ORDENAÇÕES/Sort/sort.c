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
			swap(&v[j-1], &v[j]);
	}
}

void merge_sort(int *v, int n){

    int *temp;

	temp = (int *) malloc(sizeof(int) * SIZE);

	if(temp == NULL){
		perror("Erro ao alocar memoria: ");
		exit(EXIT_FAILURE);
	}

	merge_sort_imp(v, temp, 0, SIZE - 1);
	free(temp);


}

void merge_sort_imp(int *v, int *temp, int esq, int dir){

	int meio = 0;

	if(esq < dir){

		meio = (esq + dir) / 2;
		merge_sort_imp(v, temp, esq, meio);
		merge_sort_imp(v,temp, meio + 1, dir);

		funde(v, temp, esq, meio, dir);
	}
	free(temp);
}

void select_sort(int *v, int n){

    int i, j, max;

    for(i = n; i > 1; i--){

       max =0;

       for(j = 1; j < i; j++)
        if(v[j] > v[max])
            max = j;

       swap(&v[i-1], &v[max]);
    }
}


void heap_sort(int *vet, int n)
{
    int i, aux;

    for(i = (n-1)/2; i >= 0; i--)
        build_heap(vet, i, n-1);

    for(i = n-1; i >= 1; i--)
    {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        build_heap(vet, 0, i - 1);
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

void funde(int *v, int *temp, int esq, int meio, int dir){

	int i, j, k;

	i = esq;
	j = esq;
	k = meio + 1;

	while(j <= meio && k <= dir)
		(v[j] < v[k]) ? (temp[i++] = v[j++]) : (temp[i++] = v[k ++]);

	while(j <= meio)
		temp[i++] = v[j++];

	for(i = esq; i < k; i++)
		v[i] = temp[i];

}

void build_heap(int *vet, int i, int k)
{
    int aux = vet[i];
    int j = i*2+1;

    while (j <= k)
    {
        if(j < k)
        {
            if(vet[j] < vet[j+1])
                j++;
        }
        if(aux < vet[j])
        {
            vet[i] = vet[j];
            i = j;
            j = 2*i +1;
        }
        else
            j = k+1;
        vet[i] = aux;
    }
}
