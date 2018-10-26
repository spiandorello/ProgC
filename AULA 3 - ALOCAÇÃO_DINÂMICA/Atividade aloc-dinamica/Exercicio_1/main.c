#include <stdio.h>
#include <stdlib.h>

int sumVector(int *vec, int n);
void *revertVector(int *vec, int n);
void revertVec(int *revec, int *vec, int n);
int main()
{
    int *vet,tamanho,i;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d",&tamanho);

    vet = malloc(sizeof(int) * tamanho);

    if(vet == NULL)
    {
        perror("main: ");
        exit(1);
    }

    for (i=0; i < tamanho; i++)
    {
        printf("Entre com o valor de v[%d]: \n",i);
        scanf("%d",&vet[i]);
    }
    printf("o somatorio dos elementodo do vetor eh : %d\n", sumVector(vet,tamanho));

    revertVector(vet,tamanho);

    for (i=0; i < tamanho; i++)
    {
        printf("vec[%d]: %d \n",i,vet[i]);
    }
    free(vet);
    return 0;
}

/*Soma os valores dos vetores*/
int sumVector(int *vec, int n)
{
    int i,soma=0;
    for(i=0; i<n; i++)
        soma += vec[i];
    return(soma);
}

/*Reverte os vetores item a*/

void *revertVector(int *vec, int n)
{
    int i,j,temp;

    for(i = 0, j= n - 1; i < j; i++, j--)
    {
        temp = *(vec + j);
        *(vec + j) = *(vec + i);
        *(vec + i) = temp;
    }
    return(vec);
}

/* Reverte os vetores item b*/

