#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "labirinto.h"
#include <stdlib.h>

#define TamPop 10
#define TAM 70

typedef struct{
    float pontos;
    int posi;
    int posj;
    int caminho[TAM];
} individuo;

void moveIndividuoInicial(int labirinto[LINHAS][COLUNAS], individuo *ind, FILE *arquivo);
void moveIndividuo(int labirinto[LINHAS][COLUNAS], individuo *ind, FILE *arquivo);
void printIndividuos(individuo *ind, FILE *arquivo);

#endif