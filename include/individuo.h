#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "labirinto.h"
#include <stdlib.h>

#define TamPop 10
#define TAM 27

typedef struct{
    float pontos;
    int posi;
    int posj;
    int caminho[TAM]; // sequencia de movimentos do individuo, dado pela numero da direçao para qual se moveu
    // 0/4: p cima, 1/5: p baixo, 2/6: esquerda, 3/7: direita
} individuo;

int moveIndividuoInicial(int labirinto[LINHAS][COLUNAS], individuo *ind, FILE *arquivo);
int moveIndividuo(int labirinto[LINHAS][COLUNAS], individuo *ind, FILE *arquivo);
void printIndividuos(individuo *ind, FILE *arquivo);

#endif
