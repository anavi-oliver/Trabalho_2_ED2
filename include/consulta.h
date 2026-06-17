#ifndef CONSULTA_H
#define CONSULTA_H

#include "grafo.h"
#include "cidade.h"
#include "svg.h"
#include <stdio.h>

/*
 * consulta.h — Processamento de comandos do arquivo .qry
 *
 * Comandos suportados (especificação do Trabalho 2):
 *
 *   @o? reg cep face num   Armazena a posição geográfica do endereço
 *                          cep/face/num no registrador reg (R0..R10).
 *                          SVG: linha vertical pontilhada vermelha + nº do reg.
 *                          TXT: reporta a coordenada do endereço.
 *
 *   mvm v x y w h          Atualiza a velocidade média das arestas dentro da
 *                          região (x,y,w,h) para v.
 *
 *   regs vl                Considera insuficientes trechos com vm < vl.
 *                          Calcula os componentes conexos.
 *                          TXT: número de componentes.
 *                          SVG: bounding boxes coloridos, 50% transparência.
 *
 *   exp vl                 Calcula a árvore geradora mínima, seleciona arestas
 *                          com vm < vl, aumenta a vm delas em 50%.
 *                          SVG: arestas selecionadas em linha grossa vermelha.
 *
 *   p? reg1 reg2 cc cr     Melhor trajeto entre origem (reg1) e destino (reg2).
 *                          Desenha o mais curto (cor cc) e o mais rápido (cr).
 *                          TXT: descrição textual; se inacessível, reporta.
 *                          SVG: percursos animados + placas I e F.
 *
 * Os registradores R0..R10 guardam referências geográficas (coordenadas)
 * obtidas via @o? e podem ser reutilizados em consultas posteriores.
 *
 * Estruturas NÃO são expostas — use apenas funções públicas.
 */

typedef void *CtxConsulta;

/**
 * Cria um contexto para processamento de consultas.
 *
 * @param grafo grafo viário (lido do .via)
 * @param cidade quadras da cidade (lido do .geo)
 * @param svgSaida SVG aberto para escrita
 * @param txtSaida TXT aberto para escrita
 * @return contexto, ou NULL em erro
 */
CtxConsulta consultaCreate(Grafo grafo, Cidade cidade,
                           ArqSvg svgSaida, FILE *txtSaida);

/**
 * Processa um arquivo .qry, executando todos os comandos em ordem.
 * Cada comando é copiado ao TXT precedido por "[*] ".
 *
 * @param caminhoQry caminho para o arquivo .qry
 * @param ctx contexto criado com consultaCreate
 * @return 0 se sucesso, -1 em erro (não abriu o arquivo)
 */
int processarQry(const char *caminhoQry, CtxConsulta ctx);

/**
 * Libera memória alocada para o contexto.
 */
void consultaDestroy(CtxConsulta ctx);

#endif /* CONSULTA_H */