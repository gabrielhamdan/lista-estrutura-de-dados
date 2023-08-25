#include <stdio.h>
#include "./lista.h"

void pegaInputUsuario();
bool validaInput();
bool incluiItem();

Item lista[20];
int usu_i, usu_cod, item_qt;

int main(int argc, char **argv) {
    usu_i = usu_cod = item_qt = 0;
    pegaInputUsuario();

    return 0;
}

void pegaInputUsuario() {
    while(true) {
        scanf("%d", &usu_i);

        if(!validaInput())
            continue;

        if(!incluiItem())
            printf("Lista cheia.\n");
        else
            printf("Item incluído na lista.\n");
    }
}

bool validaInput() {
    return usu_i >= 0 && usu_i <= 19;
}

bool incluiItem() {
    if(item_qt >= 2) return false;

    item_qt++;

    return true;
}