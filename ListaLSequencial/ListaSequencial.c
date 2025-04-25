#include "ListaSequencial.h"
#include <stdio.h>
#include <stdlib.h>
struct lista
{
    int *valores;
    int tam;
    int quant;
    int ordenada;
    int repeticoes;
};
void excluir_em_index(LSLista *lista,int index,int quantos);
void inserir_em_index(LSLista *lista,int index,int valor);
int busca_binaria(LSLista *lista,int valor,int *index);

//cria a lista
LSLista* LS_criar(int tam, int quant, int ordenada,int repeticoes) {
    LSLista *lista = (LSLista*) malloc(sizeof(LSLista));
    if (!lista) return NULL;
    lista->valores = (int*) malloc(tam * sizeof(int));
    if (!lista->valores) return NULL;
    lista->tam = tam;
    lista->quant = quant;
    lista->ordenada = ordenada;
    lista->repeticoes = repeticoes;
    return lista;
}

//destroi completamente a lista
void LS_destruir(LSLista* lista) {
    if (lista) {
    free(lista->valores);
    free(lista);
    }
}

// insere o elemento na lista, dependendo se ela e ordenadada e/ou tem repeticoesetições
int LS_inserir(LSLista* lista, int valor) {
if (lista->quant == lista->tam) return 0;
    if(!lista->ordenada){
        int i;
        if (!lista->repeticoes){
            for (i=0;i < lista->quant;i++){
                if (lista->valores[i] == valor){
                    return 0;
                }
            }
        }
        lista->valores[lista->quant] = valor;
        lista->quant++;
    } else {
        int index,achou;
        achou = busca_binaria(lista,valor,&index);
        if (!lista->repeticoes && achou) return 0;
        inserir_em_index(lista,index,valor);
    }
    return 1;
}

//Remove todos as apariçoes de um elemento na lista, dependendo se ela é ordenadaicada e/ou tem repeticoesetições
int LS_remover(LSLista* lista, int valor) {
    if (lista->quant == 0) return 0;
    int i,achou = 0;
    if (!lista->ordenada){
        for(i=0;i < lista->quant;i++){
            if (lista->valores[i] == valor){
                excluir_em_index(lista,i,1);
                if (!lista->repeticoes) return 1;
                achou = 1;

            }
        }
        return achou;
    }
    else {
        int index,quantos = 1;
        achou = busca_binaria(lista,valor,&index);
        if (!achou) return 0;
        if (lista->repeticoes){
            for(i = index-1; lista->valores[i] == valor;i--)
            {
                index--;
                quantos++;
            }
            for(i = index+quantos; lista->valores[i] == valor;i++)
            {
                quantos++;
            }
        }
        excluir_em_index(lista,index,quantos);
        return 1;
    }
}

//busca por um valor na lista
int LS_busca(LSLista *lista,int valor,int *index){
    int i;
    if(lista->ordenada){
        return busca_binaria(lista,valor,index);
    } else {
        for (i=0;i < lista->quant;i++){
            if (lista->valores[i] == valor){
                *index = i;
                return 1;
            }
        }
        *index = i;
        return 0;
    }
}

//pega o valor do indicie passado
int LS_pegarIndice(LSLista *lista,int index){
    if (index > lista->quant) return -1;
    return lista->valores[index];
}

//retorna a quantidade de elementos da lista
int LS_quantidade(LSLista* lista) {
    return lista->quant;
}

//exibe a lista no terminal
void LS_imprimir(LSLista* lista) {
    for (int i = 0; i < lista->quant; i++)
    printf("%i, ",lista->valores[i]);
}

//função auxiliar
void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = n - 1; k > 0; k--) {
        printf("\n[%d] ", k);

        for (j = 0; j < k; j++) {
            printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

//funcao auxiliar
int busca_binaria(LSLista *lista,int valor,int *index){
    int min = 0, max = lista->quant-1, med;
    while (min <= max)
    {
        med = min + (max - min) / 2;
        if (lista->valores[med] > valor) max = med - 1;
        else if (lista->valores[med] < valor) min = med + 1;
        else {
            *index = med;
            return 1;
        }
    }
    *index = min;
    return 0;
}

//funcao auxiliar
void inserir_em_index(LSLista *lista,int index,int valor){
    int i;
    for (i = lista->quant; i > index;i--){
        lista->valores[i] = lista->valores[i-1];
    }
    lista->valores[index] = valor;
    lista->quant++;
}

//funcao auxiliar
void excluir_em_index(LSLista *lista,int index,int quantos){
    int i;
    for (i = index; i < lista->quant - quantos;i++){
        lista->valores[i] = lista->valores[i+quantos];
    }
    lista->quant -= quantos;
}