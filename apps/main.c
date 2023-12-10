#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesEvolucao.h"
#include "labirinto.h"

/*MARCELO EDUARDO REGINATO
NUSP: 13676965*/

int main(){
    ind individuos[TamPop];
    float fitness[TamPop];
    srand(time(NULL));

    int labirinto[LINHAS][COLUNAS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // individuos[0].avaliacao = 0;
    // individuos[0].posi = LINHAS - 2;
    // individuos[0].posj = COLUNAS - 2;

    // labirinto[individuos[0].posi][individuos[0].posj] = 3;

    // moveIndividuo(labirinto, individuos[0], &y);
    // printLabirinto(labirinto);


    initpop(individuos, labirinto);
    for(int i = 0; i < 2; i++)
        avalia(fitness, individuos, labirinto);
    elitismo(fitness, individuos);

    return 0;
}
