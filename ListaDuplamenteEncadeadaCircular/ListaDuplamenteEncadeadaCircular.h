typedef struct no LDECNo;
typedef struct lista LDECLista;

LDECLista* LDEC_criar(int ordenada, int repeticoes);

void LDEC_destruir(LDECLista* lista);
int LDEC_inserir(LDECLista* lista, int valor);
int LDEC_remover(LDECLista* lista, int valor);
int LDEC_vazia(LDECLista* lista);
void LDEC_imprimir(LDECLista* lista);
int LDEC_contem(LDECLista* lista, int valor);