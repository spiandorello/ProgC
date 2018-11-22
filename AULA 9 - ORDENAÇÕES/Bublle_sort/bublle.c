#include "bublle.h"
#include <stdio.h>
#include <stdlib.h>

void bubble(int *v, int n){

	int i, j;

	for(i = n; i > 1; i--)
		for(j = 0; j < i -1; j++)
			if(v[j] > v[j + 1])
				swap(&v[j], &v[j + 1]);
}

void swap(int *a, int *b){

	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}


