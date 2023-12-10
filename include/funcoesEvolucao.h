#ifndef FUNCOESEVOLUCAO_H
#define FUNCOESEVOLUCAO_H

#include "individuo.h"
#define TamPop 2
#define Exterminio 2

void initpop(ind *ind, int labirinto[LINHAS][COLUNAS]);
void avalia(float *fit, ind *ind, int labirinto[LINHAS][COLUNAS]);
void exterminio(ind *ind);
int* elitismo(ind *ind);
// void crossover(ind ind, ind *novaPop, int maxfit1, int maxfit2);
ind* cruzamento(ind *ind);

#endif