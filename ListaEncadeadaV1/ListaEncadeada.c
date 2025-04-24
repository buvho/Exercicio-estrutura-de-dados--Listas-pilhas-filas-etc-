#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    LENo* prox;
};

struct lista
{
    LENo* cabeca;
    int classif, rep;
};

static LENo* no_criar(int v);

LELista* LE_criar() {
    LELista *lista = (LELista*) malloc(sizeof(LELista));
    if (!lista) return NULL;
    lista->cabeca = _LE_no_criar(0);
    if (!lista->cabeca) return NULL;
    return lista;
}

void LE_destruir(LELista* lista) {
    LENo *n1 = lista->cabeca;
    LENo *n2;
    while(n1) {
        n2 = n1;
        n1 = n1->prox;
        free(n2);
    }
    free(lista);
}

int LE_inserir_inicio(LELista* lista, int valor) {
    LENo *n1 = lista->cabeca;
    LENo *n2 = n1->prox;
    LENo *nNovo = no_criar(valor);
    n1->prox = nNovo;
    nNovo->prox = n2;
    return 1;
}

int LE_inserir_fim(LELista* lista, int valor) {
    LENo *n1 = lista->cabeca;
    LENo *n2;
    while(n1) {
        n2 = n1;
        n1 = n1->prox;
    }
    n2->prox = LE_criar(valor);
    return 1;
}

void LE_remover(LELista* lista, int valor) {
    LENo *n1 = lista->cabeca->prox;
    LENo *n2 = lista->cabeca;
    while(n1) {
        if (n1->valor == valor) {
            n2->prox = n1->prox;
            free(n1);
            n1 = n2->prox;
        } else {
            n2 = n1;
            n1 = n1->prox;
        }
    }
}

int LE_vazia(LELista* lista) {
    if (!lista->cabeca->prox) return 1;
    return 0;
}

void LE_imprimir(LELista* lista) {
    LENo *n1 = lista->cabeca->prox;
    while (n1) {
        printf("%i, ", n1->valor);
        n1 = n1->prox;
    } 
}

LENo* no_criar(int v) {
    LENo *no = (LENo*) malloc(sizeof(LENo));
    no->valor = v;
    no->prox = NULL;
    return no;
}

int LE_contem(LELista *lista, int valor) {
    LENo *n1 = lista->cabeca->prox;
    LENo *n2 = lista->cabeca;
    while(n1) {
        if (n1->valor == valor) {
            return 1;
        }
        n2 = n1;
        n1 = n1->prox;
    }
    return 0;
}