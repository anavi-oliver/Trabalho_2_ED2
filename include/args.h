#ifndef ARGS_H
#define ARGS_H

/*
 * args.h — Tratamento dos argumentos de linha de comando
 *
 * Formato: ted [-e path] -f arq.geo [-q consulta.qry] [-v arqvias.via] -o dir
 *
 *   -e path   : diretório-base de entrada (BED). Opcional.
 *   -f arq    : arquivo .geo da cidade. Obrigatório.
 *   -q arq    : arquivo .qry de consultas. Opcional.
 *   -v arq    : arquivo .via do sistema viário. Opcional.
 *   -o dir    : diretório-base de saída (BSD). Obrigatório.
 *
 * Estruturas NÃO são expostas — use apenas funções públicas.
 */

typedef void *Args;

/**
 * Faz o parsing de argc/argv.
 * @return estrutura Args preenchida, ou NULL se argumentos obrigatórios faltam
 */
Args parsearArgs(int argc, char *argv[]);

/**
 * Retorna o diretório-base de entrada (BED), ou "." se não informado.
 */
const char *argsGetDirEntrada(Args a);

/**
 * Retorna o diretório-base de saída (BSD).
 */
const char *argsGetDirSaida(Args a);

/**
 * Retorna o caminho completo do arquivo .geo (BED + nome).
 */
const char *argsGetGeoPath(Args a);

/**
 * Retorna o caminho completo do arquivo .qry, ou NULL se não informado.
 */
const char *argsGetQryPath(Args a);

/**
 * Retorna o caminho completo do arquivo .via, ou NULL se não informado.
 */
const char *argsGetViaPath(Args a);

/**
 * Calcula o nome-base de saída (combinação de geo e qry, sem extensão).
 * Ex: "c1.geo" + "consulta.qry" -> "c1-consulta"
 *     "c1.geo" sozinho          -> "c1"
 *
 * @param a estrutura Args
 * @param out buffer de saída
 * @param tam tamanho do buffer
 */
void argsBaseSaida(Args a, char *out, int tam);

/**
 * Libera memória alocada para Args.
 */
void destruirArgs(Args a);

#endif /* ARGS_H */