#include "labirinto.h"
#include <stdlib.h>

#define maxx 2000

typedef struct{
    float avaliacao;
    int posi;
    int posj;
}ind;

void moveIndividuo(int labirinto[LINHAS][COLUNAS], ind ind, float *pontos);