#ifndef SVG_H
#define SVG_H

/*
 * svg.h — Criação e escrita de arquivos SVG
 *
 * Reutilizado do Projeto 1 e estendido para o Projeto 2 com:
 *   - linhas (segmentos de rua, endereços pontilhados)
 *   - retângulos envolventes transparentes (componentes conexas)
 *   - caminhos animados (percursos com animateMotion)
 *   - placas de início/fim (I e F)
 *
 * Estruturas NÃO são expostas — use apenas funções públicas.
 */

typedef void *ArqSvg;

/* ── ciclo de vida ─────────────────────────────────────────────────────── */

/** Cria um SVG com cabeçalho. Retorna NULL se não conseguir criar o arquivo. */
ArqSvg abrirSvg(const char *caminho);

/** Emite </svg>, fecha o arquivo e libera memória. */
void fecharSvg(ArqSvg svg);

/* ── formas básicas (Projeto 1) ────────────────────────────────────────── */

/** Desenha uma quadra (rect) com label do CEP. */
void svgQuadra(ArqSvg svg,
               double x, double y, double w, double h,
               double sw,
               const char *corFill, const char *corStroke,
               const char *cep);

/** Texto genérico. */
void svgTexto(ArqSvg svg,
              double x, double y,
              const char *cor, double tamanho,
              const char *texto);

/** Círculo simples (usado para vértices do grafo). */
void svgCirculo(ArqSvg svg, double cx, double cy, double r,
                const char *corFill, const char *corStroke);

/* ── novas formas (Projeto 2) ──────────────────────────────────────────── */

/**
 * Desenha uma linha (segmento de rua).
 * @param tracejada 1 para linha pontilhada, 0 para contínua
 */
void svgLinha(ArqSvg svg, double x1, double y1, double x2, double y2,
              const char *cor, double espessura, int tracejada);

/**
 * Desenha um retângulo envolvente (bounding box) com transparência.
 * Usado pelo comando 'regs' para destacar componentes conexas.
 *
 * @param opacidade valor entre 0.0 e 1.0 (ex: 0.5 = 50%)
 */
void svgRetanguloEnvolvente(ArqSvg svg,
                            double x, double y, double w, double h,
                            const char *cor, double opacidade);

/**
 * Desenha um caminho (path) com animação de uma figura percorrendo-o.
 * Usado pelo comando 'p?' para mostrar os percursos.
 *
 * @param svg arquivo SVG
 * @param pontosX array de coordenadas X dos vértices do caminho
 * @param pontosY array de coordenadas Y dos vértices do caminho
 * @param n número de pontos
 * @param cor cor do caminho
 * @param idPath identificador único do path (para o animateMotion)
 */
void svgCaminhoAnimado(ArqSvg svg,
                       const double *pontosX, const double *pontosY, int n,
                       const char *cor, const char *idPath);

/**
 * Desenha uma "placa" com uma letra (I para início, F para fim).
 */
void svgPlaca(ArqSvg svg, double x, double y, const char *letra,
              const char *cor);

#endif /* SVG_H */