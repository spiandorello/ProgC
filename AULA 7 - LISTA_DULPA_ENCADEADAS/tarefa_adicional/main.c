#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"


int main()
{
    no_t* elemento = NULL;
    lista_enc_t* lista = NULL;

    char nome_1[] = "IFSC";
    char nome_2[] = "DAELN";
    char nome_3[] = "Eletronica";
    char nome_4[] = "Eletronicaaaaaaaaaaaaaa";


    lista = criar_lista_enc();

    elemento = criar_no((void*)nome_1);
    add_cabeca(lista, elemento);

    elemento = criar_no((void*)nome_2);
    add_cabeca(lista, elemento);

    elemento = criar_no((void*)nome_3);
    add_cabeca(lista, elemento);

    elemento = criar_no((void*)nome_4);
    add_cabeca(lista, elemento);

    //while(!lista_vazia(lista))
      //  remove_cauda(lista);

    while(!lista_vazia(lista))
      remove_cabeca(lista);

    imprimi_lista(lista);
    //imprimi_lista_tras(lista);

    free(lista);

    return 0;
}
