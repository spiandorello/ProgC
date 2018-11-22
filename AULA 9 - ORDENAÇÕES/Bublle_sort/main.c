#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>

#include "bublle.h"

#define SIZE 100000

int main(){

	int *vet;
	int i;
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

	bubble(vet, SIZE);

	Ticks[1] = clock();

	tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	printf("Tempo gasto: %g ms.", tempo);



	//for(i=0; i < SIZE ; i++)
	//	printf("%d ", vet[i]);

	return(0);
}
