#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>

#include "sort.h"

/*                            IFSC                     MEU_PC
    BUBLLE                    13.939  s                18.826   s
    QUICK                     9.25   ms                11.650   ms
    INSERT_SORT_DIRETA        3.735  s                 5.101    s
    INSERT_SORT_BIN           3.644  s                 2.040    s
    MERGE                     9.25   ms                13.25    ms
    SELECT                    4.325  s                 4.450    s
    Heap                                               13.950   ms
*/


int main()
{

    int *vet;
    int i, j;
    //int v[] = {10, 9, 8, 7, 6, 5};

    double tempo = 0;
    clock_t Ticks[2];

    vet = (int *) malloc(sizeof(int) * SIZE);

    if(vet == NULL)
    {
        perror("Erro ao alocar memoria: ");
        exit(EXIT_FAILURE);
    }

    for(j=0; j < 20; j++)
    {
        srand(getpid() ^ time(NULL));

        for(i=0; i < SIZE; i++)
            vet[i] = rand();

        Ticks[0] = clock();

        //bubble(vet, SIZE);
        //qs(vet, 0, SIZE - 1);
        //insertsort_direta(vet, SIZE);
        //insertsort_binaria(vet, SIZE);
       // merge_sort(vet, SIZE);
        select_sort(vet, SIZE);
        //heap_sort(vet, SIZE);

        Ticks[1] = clock();

        tempo += (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("Tempo gasto: %lf ms.\n", tempo);

        //for(i=0; i < 6 ; i++)
        //printf("%d   ", v[i]);
    }
    printf("%f", tempo/20);
    free(vet);
    return(0);
}
