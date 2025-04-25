#include "ListaSequencial.h"
#include <stdio.h>

int main() {
    // Cria lista ordenada sem repetições (tamanho 5)
    LSLista *lista = LS_criar(5, 0, 1, 0);
    
    // Teste de inserção
    printf("Inserindo valores:\n");
    LS_inserir(lista, 3); 
    LS_inserir(lista, 1); 
    LS_inserir(lista, 4); 
    LS_inserir(lista, 1); 
    
    // Mostra lista
    printf("\nLista atual: ");
    LS_imprimir(lista);
    printf("\nQuantidade: %d\n", LS_quantidade(lista));
    
    // Teste de busca
    int pos;
    if(LS_busca(lista, 3, &pos)) {
        printf("\nValor na pos %d\n", pos);
    }
    
    // Teste de remoção
    printf("\nRemovendo 3\n");
    LS_remover(lista, 3);
    printf("após remoção: ");
    LS_imprimir(lista);
    
    // Teste de acesso por índice
    printf("\n\nposição 0: %d\n", LS_pegarIndice(lista, 0));
    
    // Limpeza
    LS_destruir(lista);
    return 0;
}