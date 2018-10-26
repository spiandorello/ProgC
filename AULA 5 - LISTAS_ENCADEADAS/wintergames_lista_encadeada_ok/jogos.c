#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogos.h"
#include "lista_enc.h"

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

lista_enc_t* process_arquivo(char *arquivo)
{
    no_t* elemento = NULL;
    lista_enc_t* lista = NULL;
    FILE *fp;
    jogos_inverno *dado;
    char buffer[TAM_BUFFER];
    int ret;
    int pos, ouro, prata, bronze, total;
    char nacao[64];

    fp = fopen(arquivo,"r");
    if(fp == NULL)
    {
        perror("process_arquivo");
        exit(EXIT_FAILURE);
    }

    lista = criar_lista_enc();

    while(fgets(buffer,TAM_BUFFER,fp) != NULL)
    {

        ret = sscanf(buffer, "%d,%63[^,],%d,%d,%d,%d\n", &pos, nacao, &ouro,
                                                        &prata, &bronze,&total);
        if(ret != 6)
        {
            fprintf(stderr,"Erro");
            exit(1);
        }

        dado = malloc(sizeof(jogos_inverno));

        dado->pos = pos;
        dado->ouro = ouro;
        dado->prata = prata;
        dado->bronze = bronze;
        dado->total = total;

        dado->nacao = malloc(strlen(nacao)+1); //tamanho da linha +  para contar o "\"
        strcpy(dado->nacao,nacao);

        elemento = criar_no((void*)(dado));
        add_cauda(lista, elemento);
    }

    return(lista);
    fclose(fp);
}

void imprimi(lista_enc_t *lista)
{
    no_t *meu_no = obter_cabeca(lista);

    while(meu_no)
    {
        jogos_inverno *jogosInver = obter_dado(meu_no);


        printf("%d\t%-60s\t%d\t%d\t%d\t%d\n",jogosInver->pos, jogosInver->nacao, jogosInver->ouro,
                                            jogosInver->bronze, jogosInver->prata, jogosInver ->total);
        meu_no = obter_proximo(meu_no);
    }
}

void free_jogos(lista_enc_t *lista)
{
    no_t *meu_no = obter_cabeca(lista);
    no_t *prox = NULL;
    jogos_inverno *dado;

    while(meu_no)
    {
        dado = obter_dado(meu_no);
        free(dado->nacao);
        free(dado);
        prox = obter_proximo(meu_no);
        free(meu_no);
        meu_no = prox;
    }
    free(lista);
}

