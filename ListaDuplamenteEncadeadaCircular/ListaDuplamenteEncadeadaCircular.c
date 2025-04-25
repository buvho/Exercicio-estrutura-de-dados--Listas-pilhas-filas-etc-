#include "ListaDuplamenteEncadeadaCircular.h"
#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    LDECNo* prox;
    LDECNo* ant;
};

struct lista
{
    LDECNo* cabeca;
    int ordenada, repeticoes;
};

// funcoes auxiliares
LDECNo* no_criar(int v);
int LDEC_inserir_inicio(LDECLista* lista, int valor);

//cria a lista
LDECLista* LDEC_criar(int ordenada, int repeticoes) {
    LDECLista *lista = (LDECLista*) malloc(sizeof(LDECLista));
    if (!lista) return NULL;
    
    lista->cabeca = no_criar(0);
    lista->cabeca->prox = lista->cabeca;
    lista->cabeca->ant = lista->cabeca;
    
    lista->ordenada = ordenada;
    lista->repeticoes = repeticoes;
    return lista;
}

//destroi completamente a lista
void LDEC_destruir(LDECLista* lista) {
    LDECNo *atual = lista->cabeca->prox;
    while(atual != lista->cabeca) {
        LDECNo *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(lista->cabeca);
    free(lista);
}

// insere o elemento na lista, dependendo se ela é ordenada e/ou tem repeticoes
int LDEC_inserir(LDECLista* lista, int valor) {
    if (!lista->ordenada) {
        if (!lista->repeticoes && LDEC_contem(lista, valor)) return 0;
        LDEC_inserir_inicio(lista, valor);
        return 1;
    }
    
    LDECNo *atual = lista->cabeca->prox;
    if (!lista->repeticoes && lista->ordenada) {
        while(atual != lista->cabeca) {
            if (atual->valor == valor) {
                return 0;
            }
            else if (atual->valor > valor) {
                break;
            }
            atual = atual->prox;
        }
        
        LDECNo *novo = no_criar(valor);
        novo->prox = atual;
        novo->ant = atual->ant;
        atual->ant->prox = novo;
        atual->ant = novo;
        return 1;
    } 
    else {
        while(atual != lista->cabeca) {
            if (atual->valor > valor) {
                break;
            }
            atual = atual->prox;
        }
        
        LDECNo *novo = no_criar(valor);
        novo->prox = atual;
        novo->ant = atual->ant;
        atual->ant->prox = novo;
        atual->ant = novo;
        return 1;
    }
}

//Remove todos as aparições de um elemento na lista, dependendo se ela é ordenada e/ou tem repeticoes
int LDEC_remover(LDECLista* lista, int valor) {
    LDECNo *atual = lista->cabeca->prox;
    int removido = 0;
    
    if (!lista->repeticoes) {
        while(atual != lista->cabeca) {
            if (atual->valor == valor) {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
                LDECNo *temp = atual;
                atual = atual->prox;
                free(temp);
                return 1;
            } else {
                atual = atual->prox;
            }
        }
        return 0;
    } 
    else {
        if(lista->ordenada) {
            while(atual != lista->cabeca) {
                if (atual->valor > valor) {
                    return removido;
                }
                else if (atual->valor == valor) {
                    atual->ant->prox = atual->prox;
                    atual->prox->ant = atual->ant;
                    LDECNo *temp = atual;
                    atual = atual->prox;
                    free(temp);
                    removido = 1;
                } else {
                    atual = atual->prox;
                }
            }
        } else {
            while(atual != lista->cabeca) {
                if (atual->valor == valor) {
                    atual->ant->prox = atual->prox;
                    atual->prox->ant = atual->ant;
                    LDECNo *temp = atual;
                    atual = atual->prox;
                    free(temp);
                    removido = 1;
                } else {
                    atual = atual->prox;
                }
            }
        }
        return removido;
    }
}

//indica se a lista esta vazia
int LDEC_vazia(LDECLista* lista) {
    return (lista->cabeca->prox == lista->cabeca);
}

//exibe a lista no terminal
void LDEC_imprimir(LDECLista* lista) {
    LDECNo *atual = lista->cabeca->prox;
    while (atual != lista->cabeca) {
        printf("%i, ", atual->valor);
        atual = atual->prox;
    }
}

//cria um no para a lista, funcao auxiliar
LDECNo* no_criar(int v) {
    LDECNo *no = (LDECNo*) malloc(sizeof(LDECNo));
    no->valor = v;
    no->prox = NULL;
    no->ant = NULL;
    return no;
}

//detecta se um elemento esta na lista ou não
int LDEC_contem(LDECLista *lista, int valor) {
    LDECNo *atual = lista->cabeca->prox;
    while(atual != lista->cabeca) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

//insere um elemento no inicio da lista, funcao auxiliar
int LDEC_inserir_inicio(LDECLista* lista, int valor) {
    LDECNo *novo = no_criar(valor);
    
    novo->prox = lista->cabeca->prox;
    novo->ant = lista->cabeca;
    lista->cabeca->prox->ant = novo;
    lista->cabeca->prox = novo;
    
    return 1;
}