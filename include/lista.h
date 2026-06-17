#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>  /* size_t */

/*
 * lista.h — Lista encadeada genérica
 *
 * Armazena cópias dos dados (de tamanho arbitrário).
 * Usada como base para a lista de adjacência do grafo.
 *
 * Estruturas NÃO são expostas — use apenas funções públicas.
 */

typedef void *Lista;
typedef void *NoLista;

/** Cria uma lista vazia. */
Lista listaCreate(void);

/** Insere um elemento no início da lista (copia tam bytes de dado). */
void listaInsereInicio(Lista l, void *dado, size_t tam);

/** Insere um elemento no fim da lista (copia tam bytes de dado). */
void listaInsereFim(Lista l, void *dado, size_t tam);

/** Retorna o primeiro nó da lista, ou NULL se vazia. */
NoLista listaGetPrimeiro(Lista l);

/** Retorna o próximo nó, ou NULL se for o último. */
NoLista listaGetProximo(NoLista no);

/** Retorna o ponteiro para o dado armazenado em um nó. */
void *listaGetDado(NoLista no);

/** Retorna o número de elementos na lista. */
int listaTamanho(Lista l);

/** Retorna 1 se a lista está vazia, 0 caso contrário. */
int listaVazia(Lista l);

/** Remove o primeiro elemento da lista. */
void listaRemoveInicio(Lista l);

/** Libera toda a memória da lista. */
void listaDestroy(Lista l);

#endif /* LISTA_H */