#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_BUFFER 100
//#define DEBUG

struct jogosInver{
    int pos;
    char *nacao;
    int ouro;
    int prata;
    int bronze;
    int total;
};
const char NOMEARQ[] = "winterGames.csv";

int main()
{
    FILE *fp = fopen(NOMEARQ,"r");
    char buffer[TAM_BUFFER], nome[64];            //buffer de texto
    int ret = 0;                        //retorno das funções
    int i = 0, linhas = 0;                          //contador de linha
    struct jogosInver *dado;

    if(fp == NULL)
    {
        perror("Erro em main: fopen");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, TAM_BUFFER, fp) != NULL)
        linhas++;
    dado = malloc(sizeof(struct jogosInver)*linhas);
    rewind(fp);

    while(fgets(buffer, TAM_BUFFER, fp) != NULL)
    {
        ret = sscanf(buffer, "%d,%64[^,],%d,%d,%d,%d\n",&(dado+i)->pos, nome, &(dado+i)->ouro, &(dado+i)->prata, &(dado+i)->bronze,&(dado+i)->total);
        if(ret != 6)
        {
            fprintf(stderr,"Erro na linha: %d",i);
            exit(1);
        }

        dado[i].nacao = malloc(strlen(nome)+1); //tamanho da linha +  para contar o "\"
        strcpy(dado[i].nacao,nome);
        printf("%d\t%-60s\t%d\t%d\t%d\t%d\n",dado[i].pos,dado[i].nacao,dado[i].ouro,dado[i].prata,dado[i].bronze,dado[i].total);
        i++;
    }

    for(i=0; i<linhas; i++)
        free(dado[i].nacao);
    free(dado);
    fclose(fp);

    return 0;
}
