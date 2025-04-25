#include <stdlib.h>

typedef int tipo; // Definindo o tipo da chave

typedef struct {
    tipo chv; // Chave de busca
    // Outros campos de informação podem ser adicionados aqui
} Tinf;

typedef struct node {
    Tinf inf;
    struct node *prox;
    struct node *ant;
} TNODE;

typedef struct {
    TNODE *prim;
} Tlista;

// Cria uma lista vazia (apenas com o nó cabeça)
int cria_lista(Tlista *pL) {
    TNODE *p = (TNODE *)malloc(sizeof(TNODE));
    if (p != NULL) {
        p->prox = p->ant = p; // Aponta para si mesmo
        pL->prim = p;
        return 1;
    }
    return 0;
}

// Verifica se a lista está vazia (excluindo o nó cabeça)
int lista_vazia(const Tlista *pL) {
    return (pL->prim->prox == pL->prim);
}

// Função auxiliar para criar um novo nó
TNODE *cria_no(Tinf inf) {
    TNODE *p = (TNODE *)malloc(sizeof(TNODE));
    if (p != NULL) {
        p->inf = inf;
        p->prox = p->ant = NULL;
    }
    return p;
}

// Busca otimizada usando sentinela
int busca(const Tlista *pL, tipo chv, TNODE **pno) {
    TNODE *p;
    pL->prim->inf.chv = chv; // Coloca chv na cabeça (sentinela)
    
    for (p = pL->prim->prox; p->inf.chv < chv; p = p->prox);
    
    *pno = p;
    if ((p != pL->prim) && (p->inf.chv == chv))
        return 1;
    return 0;
}

// Inclui elemento na lista ordenada
int inclui_LDEOCCab(Tlista *pL, Tinf inf) {
    TNODE *p, *pno;
    
    if (busca(pL, inf.chv, &pno))
        return -1; // Elemento já existe
    
    p = cria_no(inf);
    if (p == NULL)
        return 0; // Falha na alocação
    
    // Insere o novo nó na posição correta
    p->prox = pno;
    p->ant = pno->ant;
    pno->ant->prox = p;
    pno->ant = p;
    
    return 1;
}

// Exclui elemento da lista
int exclui(Tlista *pL, tipo chv, Tinf *inf) {
    TNODE *pno;
    
    if (lista_vazia(pL))
        return 0; // Lista vazia
    
    if (!busca(pL, chv, &pno))
        return -1; // Elemento não encontrado
    
    *inf = pno->inf; // Retorna a informação do nó
    
    // Remove o nó da lista
    pno->ant->prox = pno->prox;
    pno->prox->ant = pno->ant;
    
    free(pno);
    return 1;
}