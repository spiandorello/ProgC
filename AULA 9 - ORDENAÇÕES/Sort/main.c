#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>

#include "sort.h"


int main(){

	int *vet;
	int i;
	//int v[] = {10, 9, 8, 7, 6, 5};

	double tempo = 0;
	clock_t Ticks[2];

	vet = (int *) malloc(sizeof(int) * SIZE);

	if(vet == NULL){
		perror("Erro ao alocar memoria: ");
		exit(EXIT_FAILURE);
	}

	srand(getpid() ^ time(NULL));

	for(i=0; i < SIZE; i++)
		vet[i] = rand();

	Ticks[0] = clock();

	//bubble(vet, SIZE);
	//qs(vet, 0, SIZE - 1);
	//insertsort_direta(vet, SIZE);
	//insertsort_binaria(vet, SIZE);
	//merge_sort(vet, SIZE);
	//select_sort(vet, SIZE);

	Ticks[1] = clock();

	tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g ms.\n", tempo);


	//for(i=0; i < 6 ; i++)
		//printf("%d   ", v[i]);

	return(0);
}
