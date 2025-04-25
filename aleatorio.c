#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int min, max, numero_aleatorio;
    
    // Define o intervalo
    min = 1;
    max = 100;
    
    // Inicializa o gerador de números aleatórios com a hora atual
    srand(time(NULL));
    
    // Gera um número aleatório entre min e max
    numero_aleatorio = min + rand() % (max - min + 1);
    
    printf("Número aleatório entre %d e %d: %d\n", min, max, numero_aleatorio);
    
    return 0;
}