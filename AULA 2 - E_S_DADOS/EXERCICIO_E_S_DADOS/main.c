#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> // para uint32_t variaveis de 32-bit sem sinal

//includes locais
//#include "local.h"

//definicoes locais
#define TAM_BUFFER 50
#define TAM_DADOS 256
// ativar depuracao
#define DEBUG



int main()
{
    //variaveis locais
    FILE *fp = NULL;            //descritor de aqruivo
    FILE *fp_saida = NULL;
    char buffer[TAM_BUFFER];   //buffer de texto

    int endereco = 0;           //endereco do array
    int dado = 0;               //dado hex lido
    int linha = 0;              //contador de linhas -> debug
    int ret = 0;                //retorno de funcoes
    uint32_t dados[TAM_DADOS];         //dados 32-bits sem sinal


    //Abre arquivo
    fp = fopen("arquivo_entrada.mif","r");
    //Verifica se foi possivel abrir aquivo
    if (fp == NULL)
    {
        perror("Error ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    //enquanto não for final de arquivo
    while (!feof(fp))
    {
        //lê linha por linha
        fgets (buffer, TAM_BUFFER, fp);

        //Leitura de dados
        //Converte a strings em "WIDTH = n\n" para número
        ret = sscanf(buffer, "%d      :       %x;\n", &endereco, &dado);

       // #ifdef DEBUG
         //   printf("Lido dado na linha %d:  [%d]  :    %x \n", linha, endereco, dado);
        //#endif // DEBUG

        //verifica se scanf conseguiu ler os dois argumentos e salva
        if (ret == 2 && endereco < TAM_DADOS)
        {
            dados[endereco] = dado;

        #ifdef DEBUG
            printf("Armazenado:  [%d]  :    %x \n", endereco, dado);
        #endif // DEBUG
        }
        linha++;
    }

    fclose(fp);

    fp_saida = fopen("saida.bin", "wb");

    //verificar se fopen está ok


    //Escrever dado em binario
    //fwrite ...
    fwrite(dados, sizeof(uint32_t), TAM_DADOS, fp_saida); //escreve width

    fclose(fp_saida);

}
