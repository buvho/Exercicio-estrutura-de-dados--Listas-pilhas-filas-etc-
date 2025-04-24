typedef struct fila tFila;

tFila* FI_criar(int tam);
void FI_destruir(tFila* lista);
int FI_inserir(tFila* lista, int valor);
int FI_remover(tFila* lista);
