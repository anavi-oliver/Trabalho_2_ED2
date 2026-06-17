#ifndef ARESTA_H
#define ARESTA_H

/*
 * aresta.h — Aresta de um grafo viário (segmento de rua)
 *
 * Uma aresta representa um segmento de rua direcionado com atributos:
 * - nome: nome da rua
 * - ldir: CEP da quadra do lado direito (ou "-" se não houver)
 * - lesq: CEP da quadra do lado esquerdo (ou "-" se não houver)
 * - cmp: comprimento do segmento em metros
 * - vm: velocidade média em m/s
 *
 * Estruturas NÃO são expostas — use apenas funções públicas.
 */

typedef void *Aresta;

/**
 * Cria uma nova aresta com os atributos de um segmento de rua.
 *
 * @param nome nome da rua (ex: "Rua_A", "Av_Principal")
 * @param ldir CEP da quadra do lado direito (ou "-")
 * @param lesq CEP da quadra do lado esquerdo (ou "-")
 * @param cmp comprimento do segmento em metros
 * @param vm velocidade média em m/s
 * @return ponteiro opaco para a aresta, ou NULL em caso de erro
 */
Aresta arestaCreate(const char *nome, const char *ldir, const char *lesq,
                    double cmp, double vm);

/**
 * Retorna o nome da rua.
 */
const char *arestaGetNome(const Aresta a);

/**
 * Retorna o CEP da quadra do lado direito (ou "-" se não existir).
 */
const char *arestaGetLdir(const Aresta a);

/**
 * Retorna o CEP da quadra do lado esquerdo (ou "-" se não existir).
 */
const char *arestaGetLesq(const Aresta a);

/**
 * Retorna o comprimento do segmento em metros.
 */
double arestaGetCmp(const Aresta a);

/**
 * Retorna a velocidade média em m/s.
 */
double arestaGetVm(const Aresta a);

/**
 * Atualiza a velocidade média (usado pelo comando 'exp').
 */
void arestaSetVm(Aresta a, double vm);

/**
 * Libera memória alocada para a aresta.
 */
void arestaDestroy(Aresta a);

#endif /* ARESTA_H */