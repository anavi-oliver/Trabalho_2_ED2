#ifndef FILA_H
#define FILA_H

#include <stddef.h>  /* size_t */

/*
 * fila.h — Fila (queue) genérica
 *
 * Usada em: BFS, Dijkstra
 */

typedef void *Fila;

/**
 * Cria uma fila vazia.
 */
Fila filaCreate(void);

/**
 * Insere um elemento no final da fila (enqueue).
 */
void filaInsere(Fila f, void *dado, size_t tam);

/**
 * Remove e retorna o primeiro elemento (dequeue).
 * Retorna NULL se fila vazia.
 */
void *filaRemove(Fila f);

/**
 * Retorna o primeiro elemento sem remover.
 */
void *filaGetPrimeiro(Fila f);

/**
 * Retorna 1 se fila vazia, 0 caso contrário.
 */
int filaVazia(Fila f);

/**
 * Libera memória da fila.
 */
void filaDestroy(Fila f);

#endif /* FILA_H */