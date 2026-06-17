#ifndef CIDADE_H
#define CIDADE_H

#include "svg.h"

/*
 * cidade.h — Armazenamento e leitura das quadras da cidade
 *
 * Reutilizado do Projeto 1. No Projeto 2 lida apenas com quadras
 * (comandos q e cq do arquivo .geo).
 *
 * Cada quadra é um retângulo identificado por um CEP, com:
 *   - âncora (x, y) no canto SUDESTE
 *   - largura (w) e altura (h)
 *   - cor de preenchimento, cor da borda, espessura da borda
 *
 * Estruturas NÃO são expostas — use apenas funções públicas.
 */

typedef void *Cidade;

/**
 * Cria uma cidade vazia (sem quadras).
 */
Cidade cidadeCreate(void);

/**
 * Lê o arquivo .geo e popula a cidade com as quadras.
 * Processa os comandos:
 *   q  cep x y w h        -> insere quadra
 *   cq sw cfill cstrk      -> cores e espessura a partir deste ponto
 *
 * @param caminhoGeo caminho completo para o arquivo .geo
 * @param cidade cidade a ser preenchida
 * @return número de quadras inseridas, ou -1 em erro
 */
int lerGeo(const char *caminhoGeo, Cidade cidade);

/**
 * Desenha todas as quadras no SVG.
 */
void desenharQuadras(Cidade cidade, ArqSvg svg);

/**
 * Busca uma quadra pelo CEP.
 * Preenche os ponteiros de saída com os atributos (se não-NULL).
 *
 * @return 1 se encontrada, 0 caso contrário
 */
int cidadeBuscaQuadra(Cidade cidade, const char *cep,
                      double *x, double *y, double *w, double *h);

/**
 * Calcula a coordenada SVG (cx, cy) de um endereço CEP/face/num.
 * A face é uma das letras N, S, L, O.
 *
 * @return 1 se a quadra existe e o cálculo foi feito, 0 caso contrário
 */
int cidadePosEndereco(Cidade cidade, const char *cep, char face, double num,
                     double *cx, double *cy);

/**
 * Retorna o número de quadras na cidade.
 */
int cidadeNumQuadras(Cidade cidade);

/**
 * Libera memória alocada para a cidade.
 */
void cidadeDestroy(Cidade cidade);

#endif /* CIDADE_H */