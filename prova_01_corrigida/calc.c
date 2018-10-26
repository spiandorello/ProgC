/*
 * calc.c
 *
 *  Created on: Sept 12, 2018
 *      Author: Renan Augusto Starke
 */

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "pilha.h"

#define TAMANHO_MAX 128


struct calculadora
{
    pilha_t* pilha;
};

calc_t* cria_calc ()
{
    calc_t *p = malloc(sizeof(calc_t));

    if (p == NULL)
    {
        perror("cria_calc:");
        exit(EXIT_FAILURE);
    }
    p->pilha = cria_pilha(TAMANHO_MAX);

    return p;
}

void operador (calc_t* c, char op)
{
    float a,b;

    if(pilha_tamanho(c->pilha) < 2)
    {
        fprintf(stderr,"Operador insuficiente\n");
        return;
    }

    b = pop(c->pilha);
    a = pop(c->pilha);

    switch(op)
    {
    case'+':
        push(a+b, c->pilha);
        break;
    case'-':
        push(a-b, c->pilha);
        break;
    case'/':
        push(a/b, c->pilha);
        break;
    case'*':
        push(a*b, c->pilha);
        break;
    }
}

void operando (calc_t* c, float v)
{
    push(v,c->pilha);
}

void imprime_operandos (calc_t *c)
{
    if(pilha_vazia(c->pilha))
    {
        fprintf(stderr, "Nenhum dado inserido");
    }
    imprime_pilha(c->pilha);
}

void libera_calc (calc_t* c)
{
    libera_pilha(c->pilha);
    free(c);
}
