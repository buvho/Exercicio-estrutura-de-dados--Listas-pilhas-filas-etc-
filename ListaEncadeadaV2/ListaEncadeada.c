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
    int ordenada, repeticoes;
};

static LENo* no_criar(int v);


//cria a lista
LELista* LE_criar(int ordenada,int repeticoes) {
    LELista *lista = (LELista*) malloc(sizeof(LELista));
    if (!lista) return NULL;
    lista->cabeca = no_criar(0);
    lista->ordenada = ordenada;
    lista->repeticoes = repeticoes;
    return lista;
}

//destroi completamente a lista
void LE_destruir(LELista* lista) {
    LENo *atual = lista->cabeca;
    LENo *proximo;
    while(atual) {
        proximo = atual;
        atual = atual->prox;
        free(proximo);
    }
    free(lista);
}

//insire um elemento no inicio da lista, funcao auxiliar
int LE_inserir_inicio(LELista* lista, int valor) {
    LENo *atual = lista->cabeca;
    LENo *anterior = atual->prox;
    atual->prox = no_criar(valor);
    atual->prox->prox = anterior;
    return 1;
}

// insere o elemento na lista, dependendo se ela e ordenadaicada e/ou tem repeticoesetições
int LE_inserir(LELista* lista, int valor) {
    if (!lista->ordenada){
        if (!lista->repeticoes && LE_contem(lista,valor)) return 0;
        LE_inserir_inicio(lista,valor);
        return 1;
    }
    
    LENo *atual = lista->cabeca->prox;
    LENo *anterior = lista->cabeca;
    if (!lista->repeticoes && lista->ordenada){
        while(atual) {
            if (atual->valor > valor){
                break;
            }
            else if (atual->valor == valor){
                return 0;
            }
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = no_criar(valor);
        anterior->prox->prox = atual;
        return 1;
    } 
    else
    {
        while(atual) {
            if (atual->valor > valor){
                break;
            }
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = no_criar(valor);
        anterior->prox->prox = atual;
        return 1;
    } 
}

//Remove todos as apariçoes de um elemento na lista, dependendo se ela é ordenadaicada e/ou tem repeticoesetições
int LE_remover(LELista* lista, int valor) {
    LENo *atual = lista->cabeca->prox;
    LENo *anterior = lista->cabeca;
    if (!lista->repeticoes){
        while(atual) {
            if (atual->valor == valor) {
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
                return 1;
            } else {
                anterior = atual;
                atual = atual->prox;
            }
        }
        return 0;
    } 
    else if(lista->repeticoes && lista->ordenada)
    {
        int achou = 0;
        while(atual) {
            if (atual->valor > valor){
                return achou;
            }
            else if (atual->valor == valor) {
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
                achou = 1;
            } else {
                anterior = atual;
                atual = atual->prox;
            }
        }
        return achou;
    } else{
        int achou = 0;
        while(atual) {
            if (atual->valor == valor) {
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
                achou = 1;
            } else {
                anterior = atual;
                atual = atual->prox;
            }
        }
        return achou;
    }
    
}

//indica se a lista esta vazia
int LE_vazia(LELista* lista) {
    if (!lista->cabeca->prox) return 1;
    return 0;
}

//exibe a lista no terminal
void LE_imprimir(LELista* lista) {
    LENo *atual = lista->cabeca->prox;
    while (atual) {
        printf("%i, ", atual->valor);
        atual = atual->prox;
    } 
}

//cria um no para a lista, funcao auxiliar
LENo* no_criar(int v) {
    LENo *no = (LENo*) malloc(sizeof(LENo));
    no->valor = v;
    no->prox = NULL;
    return no;
}

//detecta se um elemento esta na lista ou não
int LE_contem(LELista *lista, int valor) {
    LENo *atual = lista->cabeca->prox;
    LENo *anterior = lista->cabeca;
    while(atual) {
        if (atual->valor == valor) {
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return 0;
}