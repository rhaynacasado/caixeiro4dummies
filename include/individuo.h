#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "labirinto.h"
#include <stdlib.h>

#define TAM 40

typedef struct{
    float pontos;
    int posi;
    int posj;
    int caminho[TAM];
}ind;

void moveIndividuoInicial(int labirinto[LINHAS][COLUNAS], ind *ind);
void moveIndividuo(int labirinto[LINHAS][COLUNAS], ind *ind);


#endif