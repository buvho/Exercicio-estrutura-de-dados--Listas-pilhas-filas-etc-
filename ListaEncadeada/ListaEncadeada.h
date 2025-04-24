// Definição do tipo de dado armazenado na lista
typedef struct no tNo;
typedef struct lista tLista;
// Funções básicas do TAD Lista
tLista* criar_lista();
void destruir_lista(tLista* lista);
int inserir_inicio(tLista* lista, int valor);
int inserir_fim(tLista* lista, int valor);
void remover_valor(tLista* lista, int valor);
int lista_vazia(tLista* lista);
void exibir_lista(tLista* lista);
int busca_lista(tLista *lista, int valor);