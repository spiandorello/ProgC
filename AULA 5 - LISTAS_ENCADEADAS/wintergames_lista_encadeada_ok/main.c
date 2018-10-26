#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"
#include "jogos.h"

int main()
{
    lista_enc_t* lista;
    lista = process_arquivo("winterGames.csv");
    imprimi(lista);
    free_jogos(lista);
    free(lista);
    return 0;
}
