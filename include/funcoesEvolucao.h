#include "individuo.h"
#define TamPop 2

void initpop(ind *ind, int labirinto[LINHAS][COLUNAS]);
void avalia(float *fit, ind *ind, int labirinto[LINHAS][COLUNAS]);
void elitismo(float *fit, ind *ind);
void moveIndividuo(int labirinto[LINHAS][COLUNAS], ind ind, float *y);