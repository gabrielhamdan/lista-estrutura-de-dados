#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./lista.h"

void imprime_menu(bool);
void pega_input_usuario();
void consulta_lista(bool);
void insere_item();
void remove_item();
void exibe_mensagem(int);
void reorganiza_lista(int);
bool valida_item(int);
bool pode_inserir_item();
bool lista_tem_item();
void flush_stdin();
void exibe_valores(int, bool);
void exibe_uso(int, bool);
void consulta_item(bool);

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
    printf(" 1. consultar lista\n");
    printf(" 2. consultar item \n");
    printf(" 3. inserir item   \n");
    printf(" 4. remover item   \n");
    printf(" 5. sair           \n");
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
            consulta_lista(true);
            break;
        case CONSULTA_ITEM:
            consulta_item(true);
            break;
        case INSERE_ITEM:
            insere_item();
            break;
        case REMOVE_ITEM:
            remove_item();
            break;
        case SAIR:
            system("clear");
            exit(EXIT_SUCCESS);
        default:
            imprime_menu(true);
    }
}

void consulta_lista(bool retornaMenu) {
    if(!lista_tem_item()) return;
    
    system("clear");

    printf("===================\n");
    printf("       LISTA       \n");
    printf("===================\n");
    for(int i = 0; i < MAX_ITEMS; i++)
        if(lista[i].em_uso)
            printf("%d. %d\n", i, lista[i].cod);

    if(!retornaMenu) return;

    printf("Pressione ENTER para retornar ao menu principal.");
    flush_stdin(); // aguarda input do usuário antes de seguir executando o código

    imprime_menu(false);
}

void consulta_item(bool retornaMenu) {
    int pos;
    if(!lista_tem_item()) return;
    
    system("clear");

    printf("Digite a posição a ser consultada: ");
    scanf("%d", &pos);
    flush_stdin();
    system("clear");

    if(lista[pos].em_uso) {
        printf("%d. %d\n", pos, lista[pos].cod);
    } else {
        exibe_mensagem(POS_INVALIDA);
        return;
    }
    
    if(!retornaMenu) return;

    printf("Pressione ENTER para retornar ao menu principal.");
    flush_stdin(); // aguarda input do usuário antes de seguir executando o código

    imprime_menu(false);
}

void insere_item() {
    system("clear");

    if(!pode_inserir_item()) return;

    int num, pos;

    printf("Informe o número a ser inserido: ");
    scanf("%d", &num);

    printf("\nInforme a posição a inserir o número: ");
    scanf("%d", &pos);

    if(pos > 0 && !lista[pos].em_uso && !lista[pos - 1].em_uso) {
        for(int i = 0; i < MAX_ITEMS; i++) {
            if(!lista[i].em_uso) {
                lista[i].cod = num;
                lista[i].em_uso = true;
                break;
            }
        }
    } else {
        for(int i = MAX_ITEMS; i >= pos; i--) {
            if(lista[i].em_uso && i != MAX_ITEMS)
                lista[i + 1] = lista[i];
        }

        lista[pos].cod = num;
        lista[pos].em_uso = true;
    }

    item_qt++;

    exibe_mensagem(ITEM_INSERIDO);
    imprime_menu(false);
}

void remove_item() {
    system("clear");

    if(!lista_tem_item()) return;

    consulta_lista(false);

    int i_item;
    printf("Informe qual item deseja remover: ");
    scanf("%d", &i_item);

    if(!valida_item(i_item) || !lista[i_item].em_uso) {
        exibe_mensagem(ITEM_INVALIDO);
        return;
    }

    lista[i_item].em_uso = false;
    item_qt--;

    reorganiza_lista(i_item);
    exibe_mensagem(ITEM_REMOVIDO);
}

void reorganiza_lista(int item) {
    for(int i = item; i < MAX_ITEMS - 1; i++) {
        lista[i] = lista[i + 1];
        lista[i + 1].em_uso = false;
    }
}

bool valida_item(int item) {
    return item >= MIN_ITEMS && item <= MAX_ITEMS;
}

bool pode_inserir_item() {
    if(item_qt == MAX_ITEMS) {
        exibe_mensagem(LISTA_CHEIA);
        return false;
    }

    return true;
}

bool lista_tem_item() {
    if(item_qt == 0) {
        exibe_mensagem(LISTA_VAZIA);
        return false;
    }

    return true;
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