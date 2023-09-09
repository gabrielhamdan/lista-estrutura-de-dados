#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./lista.h"

void imprime_menu(bool);
void pega_input_usuario();
void consulta_lista();
void insere_item();
void remove_item();
void reorganiza_lista(int);
bool valida_item(int);
bool pode_inserir_item();
void exibe_mensagem(int);
void flush_stdin();

Item lista[MAX_ITEMS];
int usu_i, usu_cod, item_qt;

int main(int argc, char **argv) {
    usu_i = usu_cod = item_qt = 0;
    imprime_menu(false);

    return 0;
}

void imprime_menu(bool op_invalida) {
    system("clear");

    printf("===================\n");
    printf("       LISTA       \n");
    printf("===================\n");
    printf(" 1 consultar lista \n");
    printf(" 2 inserir item    \n");
    printf(" 3 remover item    \n");
    if(op_invalida)
        printf("= opção  inválida =\n");
    else
        printf("===================\n");
    
    pega_input_usuario();
}

void pega_input_usuario() {
    scanf("%d", &usu_i);
    flush_stdin();

    switch(usu_i) {
        case CONSULTA_LISTA:
            consulta_lista();
            break;
        case INSERE_ITEM:
            insere_item();
            break;
        case REMOVE_ITEM:
            remove_item();
            break;
        default:
            imprime_menu(true);
    }
}

void consulta_lista() {
    if(item_qt == 0) {
        exibe_mensagem(LISTA_VAZIA);
        return;
    }
    
    system("clear");

    // itera lista e imprime o que estiver em_uso

    printf("Pressione ENTER para retornar ao menu principal.");
    flush_stdin(); // aguarda input do usuário antes de seguir executando o código

    imprime_menu(false);
}

void insere_item() {
    
}

void remove_item() {
    system("clear");

    int item;
    printf("Informe qual item deseja remover: ");
    scanf("%d", &item);

    if(!valida_item(item))
        exibe_mensagem(ITEM_INVALIDO);

    lista[item].em_uso = false;
    item_qt--;

    reorganiza_lista(item);
}

void reorganiza_lista(int item) {

}

bool valida_item(int item) {
    return item >= MIN_ITEMS && item <= MAX_ITEMS;
}

bool pode_inserir_item() {
    return item_qt < MAX_ITEMS;
}

void exibe_mensagem(int cod_msg) {
    system("clear");
    printf("%s\n", MENSAGEM[cod_msg]);
    sleep(1.5);
    imprime_menu(false);
}

void flush_stdin() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}