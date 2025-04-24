typedef struct pilha tPilha;

tPilha* PI_criar(int capacidade);
void PI_destruir(tPilha* pilha);
int PI_empilhar(tPilha* pilha, int valor);
int PI_desempilhar(tPilha* pilha);
