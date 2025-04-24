#include <stdio.h>
#include "Fila.h"

int main() {
    // 1. Teste: Criar fila e verificar inserção/remoção básica
    printf("=== TESTE 1: Comportamento FIFO ===\n");
    tFila *fila = FI_criar(5);  // Capacidade 5 (suporta até 4 elementos + dummy)

    // Insere 3 elementos
    FI_inserir(fila, 10);
    FI_inserir(fila, 20);
    FI_inserir(fila, 30);

    // Remove e verifica ordem (FIFO)
    printf("Removido: %d (esperado: 10)\n", FI_remover(fila));
    printf("Removido: %d (esperado: 20)\n", FI_remover(fila));
    printf("Removido: %d (esperado: 30)\n", FI_remover(fila));

    // 2. Teste: Fila vazia
    printf("\n=== TESTE 2: Fila vazia ===\n");
    printf("Removendo com fila vazia: %d (esperado: 0 ou erro)\n", FI_remover(fila));

    // 3. Teste: Fila cheia (capacidade 5 = 4 elementos + dummy)
    printf("\n=== TESTE 3: Fila cheia ===\n");
    FI_inserir(fila, 40);
    FI_inserir(fila, 50);
    FI_inserir(fila, 60);
    FI_inserir(fila, 70);  // Último elemento possível (4º)

    // Tenta inserir além do limite
    printf("Tentando inserir 80 (fila cheia): %s\n", 
           FI_inserir(fila, 80) ? "Sucesso (ERRO!)" : "Falha (CORRETO!)");

    // 4. Teste: Comportamento circular (remove e insere novamente)
    printf("\n=== TESTE 4: Comportamento circular ===\n");
    printf("Removido: %d (abre espaço)\n", FI_remover(fila));  // Remove 40
    printf("Inserindo 90: %s\n", FI_inserir(fila, 90) ? "Sucesso (CORRETO!)" : "Falha (ERRO!)");

    // Remove o resto
    while (1) {
        int val = FI_remover(fila);
        if (val == 0) break;  // Fila vazia
        printf("Removido: %d\n", val);
    }

    // 5. Teste: Destruição da fila
    printf("\n=== TESTE 5: Destruir fila ===\n");
    FI_destruir(fila);
    printf("Fila destruída (sem erros = OK)\n");

    return 0;
}