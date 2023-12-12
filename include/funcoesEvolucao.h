#ifndef FUNCOESEVOLUCAO_H
#define FUNCOESEVOLUCAO_H

#include "individuo.h"
#include <time.h>

#define Exterminio 2

void initpop(individuo *ind, int labirinto[LINHAS][COLUNAS]);
void avalia(individuo *ind, int labirinto[LINHAS][COLUNAS]);
void exterminio(individuo *ind);
void elitismo(individuo *ind, int *maxfit1, int *maxfit2);
individuo misturaGene(individuo indini, individuo indfim);
void crossover(individuo *ind, int maxfit1, int maxfit2);
void cruzamento(individuo *ind);

#endif