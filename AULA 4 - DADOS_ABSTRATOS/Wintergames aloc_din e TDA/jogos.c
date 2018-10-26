#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogos.h"

#define TAM_BUFFER 100

struct jogosInver
{
    int pos;
    char *nacao;
    int ouro;
    int prata;
    int bronze;
    int total;
};

//abrir o arquivo
jogos_inverno* process_arquivo(char *arquivo, int* lines)
{
    FILE *fp;
    char buffer[TAM_BUFFER], nome[64];            //buffer de texto
    int linhas = 0;                         //contador de linha
    int ret,i=0;
    jogos_inverno *dado;

    fp = fopen(arquivo,"r");

    if(fp == NULL)
    {
        perror("process_arquivo");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, TAM_BUFFER, fp) != NULL)
        linhas++;

    dado = (malloc(sizeof(struct jogosInver)*linhas));
    rewind(fp);

    while(fgets(buffer, TAM_BUFFER, fp) != NULL)
    {
        ret = sscanf(buffer, "%d,%64[^,],%d,%d,%d,%d\n",&(dado+i)->pos, nome, &(dado+i)->ouro,
                                                        &(dado+i)->prata, &(dado+i)->bronze,&(dado+i)->total);
        if(ret != 6)
        {
            fprintf(stderr,"Erro na linha: %d",i);
            exit(1);
        }
        dado[i].nacao = malloc(strlen(nome)+1); //tamanho da linha +  para contar o "\"
        strcpy(dado[i].nacao,nome);
        i++;
    }
    *lines = i;
    fclose(fp);
    return(dado);
}

void mostra(jogos_inverno *dado, int lines)
{
    for(int i=0; i<lines; i++)
        printf("%d\t%-60s\t%d\t%d\t%d\t%d\n",dado[i].pos,dado[i].nacao,dado[i].ouro,dado[i].prata,dado[i].bronze,dado[i].total);
}

void libera(jogos_inverno *dado, int lines)
{
    for(int i=0; i<lines; i++)
        free(dado[i].nacao);
    free(dado);
}





