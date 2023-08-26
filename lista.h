#ifndef __LISTA_H
#define __LISTA_H

#include <stdbool.h>

#define MIN_ITEMS 0
#define MAX_ITEMS 14
#define MENSAGEM ((char *[]){"Item inválido.", "A lista está cheia.", "A lista está vazia."})

enum OPCAO{CONSULTA_LISTA = 1, INSERE_ITEM, REMOVE_ITEM};
enum COD_MENSAGEM{ITEM_INVALIDO, LISTA_CHEIA, LISTA_VAZIA};

typedef struct Lista
{
    int cod;
    bool em_uso;
} Item;


#endif