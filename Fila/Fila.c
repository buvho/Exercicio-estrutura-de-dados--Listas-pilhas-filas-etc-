#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

struct fila
{
    int *valores;
    int tam;
    int ult;
    int prim;
};

tFila *FI_criar(int tam) {
    tFila *fila = (tFila*) malloc(sizeof(tFila));
    fila->valores = (int*) malloc(tam * sizeof(int));
    fila->ult = 0;
    fila->prim = 0;
    fila->tam = tam;
    return fila;
}
//destroi completamente a fila
void FI_destruir(tFila* fila) {
    free(fila->valores);
    free(fila);
}

// insere o elemento na fila
int FI_inserir(tFila* fila, int valor) {
    if (fila->ult + 1 % fila->tam == fila->prim) return 0;

    fila->valores[fila->ult] = valor;
    fila->ult = (fila->ult + 1) % fila->tam;
    return 1;
}

//Remove e retorna o primeiro elemento da fila
int FI_remover(tFila* fila) {
    if (fila->ult == fila->prim) return 0;

    int valor = fila->valores[fila->prim];
    fila->prim = (fila->prim + 1) % fila->tam;
    return valor;
}
