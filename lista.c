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
void exibe_valores(int, bool);
void exibe_uso(int, bool);

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

    printf("Pressione qualquer tecla para retornar ao menu principal.");
    flush_stdin(); // aguarda qualquer input do usuário antes de seguir executando o código

    imprime_menu(false);
}

void insere_item() {
    int num, pos;
    printf("Informe o número a ser inserido. ");
    scanf("%d", &num);
    printf("\nInforme a posição a inserir o número: ");
    scanf("%d", &pos);

    if(pode_inserir_item()){
        if(!lista[pos].em_uso){
            for(int j=0;j<MAX_ITEMS;j++){
                if(!lista[j].em_uso){
                    lista[j].cod=num;
                    lista[j].em_uso=1;
                    item_qt+=1;
                    break;
                }
            }

        }else{
            for(int i=MAX_ITEMS;i>=(pos+1);i--){
                if(lista[i-1].em_uso){
                lista[i].cod = lista[i-1].cod;
                lista[i].em_uso=true;
                }
            }
            lista[pos].cod=num;
            item_qt+=1;
        }
        }else{
            exibe_mensagem(LISTA_CHEIA);
        }
    exibe_valores(0, false);
    exibe_uso(2, true);
    imprime_menu(false);

}

void remove_item() {
    system("clear");

    int pos;
    printf("Informe qual item deseja remover: ");
    scanf("%d", &pos);

    if(!valida_item(pos))
        exibe_mensagem(ITEM_INVALIDO);

    //lista[pos].em_uso = false; // desta forma irá ignorar se a lista foi reordenada.
    item_qt--;

    reorganiza_lista(pos);
    lista[item_qt].em_uso = false; // dessa forma ele irá atribuir vacância no último item da lista após reorg.

    exibe_valores(0, false);
    exibe_uso(2, true);
    imprime_menu(false);
}

void reorganiza_lista(int pos) {
    for(int i = pos; i<MAX_ITEMS; i++){
        if(lista[pos+1].em_uso){
            lista[pos].cod = lista[pos+1].cod;
        }
    }

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

void exibe_valores(int duration, bool clear) {
    int i;
    for(i=MIN_ITEMS;i<MAX_ITEMS;i++){
        printf("%d ", lista[i].cod);
    }
    printf("\n");
    sleep(duration);
    if(clear){
    system("clear");
    }
}


void exibe_uso(int duration, bool clear) {
    int i;
    for(i=MIN_ITEMS;i<MAX_ITEMS;i++){
        printf("%d ", lista[i].em_uso);
    }
    printf("\n");
    sleep(duration);
    if(clear){
    system("clear");
    }
}