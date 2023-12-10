#include "labirinto.h"
#include <stdlib.h>

#define maxx 2000

typedef struct{
    float pontos;
    int posi;
    int posj;
}ind;

void moveIndividuo(int labirinto[LINHAS][COLUNAS], ind *ind);