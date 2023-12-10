#ifndef FUNCOESEVOLUCAO_H
#define FUNCOESEVOLUCAO_H

#include "individuo.h"
#include <time.h>

#define TamPop 2
#define Exterminio 2

void initpop(individuo *ind, int labirinto[LINHAS][COLUNAS]);
void avalia(individuo *ind, int labirinto[LINHAS][COLUNAS]);
void exterminio(individuo *ind);
int* elitismo(individuo *ind);
individuo misturaGene(individuo indini, individuo indfim);
void crossover(individuo *ind, individuo *novaPop, int maxfit1, int maxfit2);
void cruzamento(individuo *ind);

#endif