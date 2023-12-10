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
} individuo;

void moveIndividuoInicial(int labirinto[LINHAS][COLUNAS], individuo *ind);
void moveIndividuo(int labirinto[LINHAS][COLUNAS], individuo *ind);


#endif