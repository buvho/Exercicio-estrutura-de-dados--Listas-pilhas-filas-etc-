#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
struct no
{
    int valor;
    tNo* prox;
};
struct lista
{
    tNo* cabeca;
};

tNo* criar_no(int v);

tLista* criar_lista(){
    tLista *lista = (tLista*) malloc (sizeof(tLista));
    if (!lista) return NULL;
    lista->cabeca = criar_no(0);
    if (!lista->cabeca) return NULL;
    return lista;
}
void destruir_lista(tLista* lista){
    tNo *n1 = lista->cabeca;
    tNo *n2;
    while(n1)
    {
        n2 = n1;
        n1 = n1->prox;
        free(n2);
    }
    free(lista);
}
int inserir_inicio(tLista* lista, int valor){
    tNo *n1 = lista->cabeca;

    tNo *n2 = n1->prox;
    tNo *nNovo = criar_no(valor);
    n1->prox = nNovo;
    nNovo->prox = n2;
    return 1;
}
int inserir_fim(tLista* lista, int valor){
    tNo *n1 = lista->cabeca;
    tNo *n2;
    while(n1)
    {
        n2 = n1;
        n1 = n1->prox;
    }
    n2->prox = criar_no(valor);
    return 1;
}

void remover_valor(tLista* lista, int valor){
    tNo *n1 = lista->cabeca->prox;
    tNo *n2 = lista->cabeca;
    while(n1)
    {
        if (n1->valor == valor){
            n2->prox = n1->prox;
            free(n1);
            n1 = n2->prox;}
        else {
            n2 = n1;
            n1 = n1->prox;
        }
    }
}
int lista_vazia(tLista* lista){
    if (!lista->cabeca->prox) return 1;
    return 0;
}

void exibir_lista(tLista* lista){
    tNo *n1 = lista->cabeca->prox;
    while (n1)
    {
        printf("%i, ",n1->valor);
        n1 = n1->prox;
    } 
    
}
tNo* criar_no(int v){
    tNo *no = (tNo*) malloc(sizeof(tNo));
    no->valor = v;
    no->prox = NULL;
    return no;
}

int busca_lista(tLista *lista, int valor){
    tNo *n1 = lista->cabeca->prox;
    tNo *n2 = lista->cabeca;
    while(n1)
    {
        if (n1->valor == valor){
            return 1;
        }
        n2 = n1;
        n1 = n1->prox;
    }
    return 0;
}
