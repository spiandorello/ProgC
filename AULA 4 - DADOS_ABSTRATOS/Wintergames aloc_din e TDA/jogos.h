#ifndef JOGOS_H_INCLUDED
#define JOGOS_H_INCLUDED

typedef struct jogosInver jogos_inverno;

jogos_inverno* process_arquivo(char *arquivo, int* lines);
void mostra(jogos_inverno *dado, int lines);
void libera(jogos_inverno *dado, int lines);
#endif // JOGOS_H_INCLUDED
