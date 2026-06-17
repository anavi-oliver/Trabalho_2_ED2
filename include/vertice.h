#ifndef VERTICE_H
#define VERTICE_H

/*
 * vertice.h — Vértice de um grafo viário (esquina, intersecção)
 *
 * Um vértice representa um ponto no mapa viário com coordenadas (x, y)
 * e um identificador único (string).
 *
 * Estruturas NÃO são expostas — use apenas funções públicas.
 */

typedef void *Vertice;

/**
 * Cria um novo vértice com ID e coordenadas.
 * @param id identificador único do vértice (ex: "v1", "esquina_A")
 * @param x coordenada X
 * @param y coordenada Y
 * @return ponteiro opaco para o vértice, ou NULL em caso de erro
 */
Vertice verticeCreate(const char *id, double x, double y);

/**
 * Retorna o identificador do vértice.
 */
const char *verticeGetId(const Vertice v);

/**
 * Retorna a coordenada X do vértice.
 */
double verticeGetX(const Vertice v);

/**
 * Retorna a coordenada Y do vértice.
 */
double verticeGetY(const Vertice v);

/**
 * Libera memória alocada para o vértice.
 */
void verticeDestroy(Vertice v);

#endif /* VERTICE_H */