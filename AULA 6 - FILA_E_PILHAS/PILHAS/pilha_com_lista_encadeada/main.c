#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "lista_enc.h"
#include "no.h"


#define DEBUG


int main()
{
    pilha_t *pilha;

    char texto[][50] = {"juca", "zeca", "coelho"};

    //cria uma pilha
    pilha = cria_pilha();
    push(texto[0], pilha);
    push(texto[0],pilha);
    push(texto[1],pilha);
    push(texto[2],pilha);

    while (!vazia(pilha))
        printf("%s\n", pop(pilha));

    free_pilha(pilha);
    return 0;
}
