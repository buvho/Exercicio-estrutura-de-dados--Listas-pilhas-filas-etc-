typedef struct no LENo;
typedef struct lista LELista;

LELista* LE_criar();
void LE_destruir(LELista* lista);
int LE_inserir_inicio(LELista* lista, int valor);
int LE_inserir_fim(LELista* lista, int valor);
void LE_remover(LELista* lista, int valor);
int LE_vazia(LELista* lista);
int LE_contem(LELista* lista, int valor);
void LE_imprimir(LELista* lista);