#include <stdio.h>
#include "./lista.h"

void pegaInputUsuario();
void consultaLista();
void insereItem();
void removeItem();
bool validaInput();
bool podeInserirItem();

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

        switch(usu_i) {
            case 1:
                consultaLista();
                break;
            case 2:
                insereItem();
                break;
            case 3:
                removeItem();
                break;
            default:
                ;
        }
    }
}

void consultaLista() {

}

void insereItem() {

}

void removeItem() {

}

bool validaInput() {
    return usu_i >= MIN_ITEMS && usu_i <= MAX_ITEMS;
}

bool podeInserirItem() {
    return true;
}