#ifndef CALC_H_
#define CALC_H_

/* Arquivo que define a interface da calculadora */
typedef struct calculadora calc_t;

/**
  * @brief Cria calculadora.
  * @param Nenhum
  * @retval calc_t:
  */
calc_t* cria_calc();

/**
  * @brief recebe um operando a ser empilhado.
  * @param char: (+,-,/,*)
  * @retval nenhum:
  */
void operando (calc_t* c, float v);

/**
  * @brief recebe um operador.
  * @param float: valor a ser empilhado
  * @param calc_t: uma calculadora válida criada.
  * @retval nenhum:
  */
void operador (calc_t* c, char op);

/**
  * @brief  impressão de operandos armazenados
  * @param calc_t: uma calculadora válida criada.
  * @retval nenhum:
  */

void imprime_operandos (calc_t *c);

/**
  * @brief Libera os dados alocados pela calculadora.
  * @param calc_t: uma calculadora válida criada.
  *
  * @retval Nenhum.
  */

void libera_calc (calc_t* c);



#endif /* CALC_H_ */
