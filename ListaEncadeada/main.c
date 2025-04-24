#include "ListaEncadeada.h"
#include <stdio.h>

int main(){
    tLista *l = criar_lista();
    inserir_inicio(l,10);
    inserir_inicio(l,15);
    exibir_lista(l);
    return 1;
}