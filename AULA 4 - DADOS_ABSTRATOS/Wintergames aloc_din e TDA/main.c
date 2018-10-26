#include <stdio.h>
#include <stdlib.h>
#include "jogos.h"

int main()
{
    int lines = 0;
    jogos_inverno *dado;

    dado = process_arquivo("winterGames.csv", &lines);
    mostra(dado, lines);
    libera(dado, lines);

    return 0;
}
