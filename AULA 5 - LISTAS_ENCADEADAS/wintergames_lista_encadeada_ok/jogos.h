#ifndef JOGOS_H_INCLUDED
#define JOGOS_H_INCLUDED

#include "lista_enc.h"

typedef struct jogosInver jogos_inverno;

lista_enc_t* process_arquivo(char* arquivo);
void imprimi(lista_enc_t* lista);
void free_jogos(lista_enc_t *lista);

#endif // JOGOS_H_INCLUDED
