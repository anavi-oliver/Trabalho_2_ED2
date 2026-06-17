#ifndef VIA_H
#define VIA_H

#include "grafo.h"

/*
 * via.h — Leitura do arquivo de sistema viário (.via)
 *
 * O arquivo .via descreve o grafo viário da cidade:
 * - Primeira linha: nv (número de vértices)
 * - Linhas v: v id x y (vértice)
 * - Linhas e: e i j ldir lesq cmp vm nome (aresta)
 */

/**
 * Lê um arquivo .via e popula o grafo.
 *
 * @param caminhoVia caminho completo para o arquivo .via
 * @param grafo grafo para ser preenchido
 * @return número de vértices inseridos, ou -1 em caso de erro
 */
int lerVia(const char *caminhoVia, Grafo grafo);

#endif /* VIA_H */