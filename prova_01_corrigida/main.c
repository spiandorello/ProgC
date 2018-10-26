/*
 ============================================================================
 Name        : stack-calc.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todos os direitos reservados
 Description : Calculadora a pós-fixada: baseado no exemplo de Estrururas
 	 	 	 	 de dados: Celes_Rangel
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(void) {

	char c;
	float v;

	calc_t* HP;

	HP = cria_calc();

	do {
		/* Lê proximo caractere não branco */
		scanf(" %c",&c);

		/* verifica se é um operador válido */
		if (c=='+' || c=='-' || c=='*' || c=='/') {
			operador(HP,c);
		}

		if (c == 'p') {
			imprime_operandos(HP);
		}

		/* Devolve caractere lido e tenta ler um número */
		else {
			ungetc(c,stdin);

			if (scanf("%f",&v) == 1){
				operando(HP,v);
			}
		}
		getchar();

	} while (c!='q');

	libera_calc(HP);

	return EXIT_SUCCESS;
}
