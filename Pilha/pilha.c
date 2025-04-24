#include "Pilha.h"
#include <stdlib.h>

struct pilha {
    int *valor;
    int topo;
    int tam;
};

tPilha* PI_criar(int tam) {
    tPilha* pilha = (tPilha*)malloc(sizeof(tPilha));
    pilha->valor = (int*)malloc(tam * sizeof(int));
    pilha->topo = -1;
    pilha->tam = tam;
    return pilha;
}

void PI_destruir(tPilha* pilha) {
    free(pilha->valor);
    free(pilha);
}

int PI_empilhar(tPilha* pilha, int valor) {
    if (pilha->topo == pilha->tam - 1) return 0;
    pilha->topo++;
    pilha->valor[pilha->topo] = valor;
    return 1;
}

int PI_desempilhar(tPilha* pilha) {
    if (pilha->topo == -1) return 0;
    pilha->topo--;
    return pilha->valor[pilha->topo];
}