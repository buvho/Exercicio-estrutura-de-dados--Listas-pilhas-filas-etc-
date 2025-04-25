#include <stdio.h>
#include "Pilha.h"

int main() {
    tPilha* pilha = PI_criar(3);

    PI_empilhar(pilha, 10);
    PI_empilhar(pilha, 20);
    PI_empilhar(pilha, 30);
    PI_empilhar(pilha, 40);

    printf("%d\n", PI_desempilhar(pilha));
    printf("%d\n", PI_desempilhar(pilha));
    printf("%d\n", PI_desempilhar(pilha));

    printf("%d\n", PI_desempilhar(pilha));

    PI_destruir(pilha);
    return 0;
}