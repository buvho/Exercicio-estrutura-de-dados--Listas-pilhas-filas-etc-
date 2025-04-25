#include "ListaDuplamenteEncadeadaCircular.h"
#include <stdio.h>

int main() {
    // Cria lista não ordenada que permite repetições
    LDECLista* lista1 = LDEC_criar(0, 1);
    
    // Testa inserção
    printf("Inserindo elementos na lista1 (não ordenada, com repetições):\n");
    LDEC_inserir(lista1, 5);
    LDEC_inserir(lista1, 2);
    LDEC_inserir(lista1, 8);
    LDEC_inserir(lista1, 2); // Repetido permitido
    
    printf("Lista1: ");
    LDEC_imprimir(lista1);
    printf("\n");
    
    // Testa remoção
    printf("\nRemovendo o valor 2:\n");
    LDEC_remover(lista1, 2);
    printf("Lista1 após remoção: ");
    LDEC_imprimir(lista1);
    printf("\n");
    
    // Cria lista ordenada sem repetições
    LDECLista* lista2 = LDEC_criar(1, 0);
    
    // Testa inserção ordenada
    printf("\nInserindo elementos na lista2 (ordenada, sem repetições):\n");
    LDEC_inserir(lista2, 7);
    LDEC_inserir(lista2, 3);
    LDEC_inserir(lista2, 5);
    LDEC_inserir(lista2, 3); // Não deve inserir (repetido)
    
    printf("Lista2: ");
    LDEC_imprimir(lista2);
    printf("\n");
    
    // Testa verificação de elemento
    printf("\nVerificando elementos na lista2:\n");
    printf("Contém 5? %s\n", LDEC_contem(lista2, 5) ? "Sim" : "Não");
    printf("Contém 9? %s\n", LDEC_contem(lista2, 9) ? "Sim" : "Não");
    
    // Testa lista vazia
    printf("\nLista2 está vazia? %s\n", LDEC_vazia(lista2) ? "Sim" : "Não");
    
    // Testa inserção no início
    printf("\nInserindo 1 no início da lista1:\n");
    LDEC_inserir_inicio(lista1, 1);
    printf("Lista1: ");
    LDEC_imprimir(lista1);
    printf("\n");
    
    // Limpeza
    LDEC_destruir(lista1);
    LDEC_destruir(lista2);
    
    return 0;
}