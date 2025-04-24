#include "ListaEncadeada.h"
#include <stdio.h>

void testar_lista(LELista* lista, const char* tipo) {
    printf("\n=== TESTANDO LISTA %s ===\n", tipo);
    
    // Testando lista vazia
    printf("Lista vazia? %s\n", LE_vazia(lista) ? "Sim" : "Não");
    
    // Inserindo elementos
    printf("\nInserindo elementos...\n");
    LE_inserir(lista, 5);
    LE_inserir(lista, 2);
    LE_inserir(lista, 8);
    LE_inserir(lista, 2); // Tentativa de inserir duplicata
    LE_inserir(lista, 3);
    LE_inserir(lista, 8); // Tentativa de inserir duplicata
    
    printf("Lista atual: ");
    LE_imprimir(lista);
    printf("\n");
    
    // Testando contém
    printf("\nTestando LE_contem:\n");
    printf("Contém 2? %s\n", LE_contem(lista, 2) ? "Sim" : "Não");
    printf("Contém 7? %s\n", LE_contem(lista, 7) ? "Sim" : "Não");
    
    // Removendo elementos
    printf("\nRemovendo elementos...\n");
    printf("Removendo 2: %s\n", LE_remover(lista, 2) ? "Sucesso" : "Falha");
    printf("Removendo 5: %s\n", LE_remover(lista, 5) ? "Sucesso" : "Falha");
    printf("Removendo 10 (inexistente): %s\n", LE_remover(lista, 10) ? "Sucesso" : "Falha");
    
    printf("Lista atual: ");
    LE_imprimir(lista);
    printf("\n");
    
    // Inserindo mais elementos
    printf("\nInserindo mais elementos...\n");
    LE_inserir(lista, 1);
    LE_inserir(lista, 10);
    LE_inserir(lista, 4);
    
    printf("Lista final: ");
    LE_imprimir(lista);
    printf("\n");
    
    printf("\n=== FIM DOS TESTES PARA LISTA %s ===\n\n", tipo);
}

int main() {
    // Testar lista não ordenada sem repetições
    LELista* lista1 = LE_criar(0, 0);
    testar_lista(lista1, "NÃO ORDENADA SEM REPETIÇÕES");
    LE_destruir(lista1);
    
    // Testar lista não ordenada com repetições
    LELista* lista2 = LE_criar(0, 1);
    testar_lista(lista2, "NÃO ORDENADA COM REPETIÇÕES");
    LE_destruir(lista2);
    
    // Testar lista ordenada sem repetições
    LELista* lista3 = LE_criar(1, 0);
    testar_lista(lista3, "ORDENADA SEM REPETIÇÕES");
    LE_destruir(lista3);
    
    // Testar lista ordenada com repetições
    LELista* lista4 = LE_criar(1, 1);
    testar_lista(lista4, "ORDENADA COM REPETIÇÕES");
    LE_destruir(lista4);
    
    return 0;
}