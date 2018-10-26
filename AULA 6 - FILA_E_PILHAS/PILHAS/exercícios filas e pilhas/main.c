#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


int main()
{
    int x = 0;
    pilha_t *pilha;

    //cria uma pilha
    pilha = cria_pilha(4);

    //empilha dados
    push(5,pilha);
    push(10,pilha);
    push(33,pilha);
    push(42,pilha);
    push(56,pilha);
    push(11,pilha);
    push(57,pilha);
    push(39,pilha);
    push(81,pilha);
    push(12,pilha);
    push(66,pilha);
    push(92,pilha);
    push(22,pilha);

    //desempilha
    x = pop(pilha);
    printf("main: pop() ---> %d\n", x);

    x = pop(pilha);
    printf("main: pop() ---> %d\n", x);

    x = pop(pilha);
    printf("main: pop() ---> %d\n", x);

    x = pop(pilha);
    printf("main: pop() ---> %d\n", x);

    x = pop(pilha);
    printf("main: pop() ---> %d\n", x);

    //desempilha
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);
    x = pop(pilha);

    free(pilha);

    return 0;
}
