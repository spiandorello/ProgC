/*
    Escreva um programa que leia um inteiro de 32-bits e imprima sua representac˜ao binaria.
    Use uma pilha.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pilha.h"

int main()
{
    uint32_t num = 1000;
    int i = 0;

    pilha_t *pilha = cria_pilha();

    while(i < 32)
    {
        (num%2 == 0)? push(0,pilha) : push(1,pilha);
        num /= 2;
        i++;
    }

    for(i=0; i<32; i++)
        printf("%d", pop(pilha));

    free(pilha);
    return 0;
}
