typedef struct lista LSLista;

LSLista* LS_criar(int tam, int quant, int ordenada, int repeticoes);
void LS_destruir(LSLista* lista);
int LS_inserir(LSLista* lista, int valor);
int LS_remover(LSLista* lista, int valor);
int LS_quantidade(LSLista* lista);
void LS_imprimir(LSLista* lista);
int LS_pegarIndice(LSLista *lista,int index);
int LS_busca(LSLista *lista,int valor,int *index);