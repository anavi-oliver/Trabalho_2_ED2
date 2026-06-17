#ifndef GRAFO_H
#define GRAFO_H

#include "vertice.h"
#include "aresta.h"
#include "lista.h"

/*
 * grafo.h — Grafo direcionado representando o sistema viário
 *
 * Implementação: lista de adjacência (lista encadeada)
 * Vértices armazenados em lista simples
 * Cada vértice tem uma lista de arestas de saída
 *
 * Estruturas NÃO são expostas — use apenas funções públicas.
 */

typedef void *Grafo;

/**
 * Cria um novo grafo vazio.
 */
Grafo grafoCreate(void);

/**
 * Insere um vértice no grafo.
 * @return 1 se inserido com sucesso, 0 se já existe, -1 em erro
 */
int grafoInsereVertice(Grafo g, const char *id, double x, double y);

/**
 * Insere uma aresta direcionada (idOrigem → idDestino).
 * @return 1 se inserida com sucesso, -1 em erro
 */
int grafoInsereAresta(Grafo g, const char *idOrigem, const char *idDestino,
                      Aresta a);

/**
 * Busca um vértice pelo ID.
 */
Vertice grafoGetVertice(Grafo g, const char *id);

/**
 * Retorna o número de vértices.
 */
int grafoNumVertices(Grafo g);

/**
 * Retorna lista de vértices do grafo.
 */
Lista grafoGetVertices(Grafo g);

/**
 * Itera sobre as arestas de saída de um vértice.
 * @param callback chamada com (idDestino, aresta, ctx)
 */
void grafoIterarArestas(Grafo g, const char *idVertice,
                        void (*callback)(const char *idDest, Aresta a, void *ctx),
                        void *ctx);

/**
 * Retorna a lista de arestas de saída de um vértice.
 */
Lista grafoGetArestas(Grafo g, const char *idVertice);

/**
 * Libera memória do grafo.
 */
void grafoDestroy(Grafo g);

#endif /* GRAFO_H */