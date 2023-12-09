#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoesEvolucao.h"

int gen = 0;

void initpop(ind *ind, int labirinto[LINHAS][COLUNAS]){
    for(int i = 0; i<TamPop; i++){
        ind[i].avaliacao = 0; // preenche o vetor com a populacao
        ind[i].posi = LINHAS - 2;
        ind[i].posj = COLUNAS - 2;
        //printf("ind[%d] = %f\n", i, ind[i]); //mostrar individuos gerados
    }
}

void avalia(float *fit, ind *ind, int labirinto[LINHAS][COLUNAS]){
    float x;
    float y;
    printf("Generacao: %d\n", gen); // printa em qual geracao esta
    gen++;
    for(int i = 0; i<TamPop; i++){
        x = ind[i].avaliacao;
        y = x;
        moveIndividuo(labirinto ,ind[i], &y);
        printf("AQUI CARALHO %d, %d\n\n", ind[i].posi, ind[i].posj);
        fit[i] = y;
        printf("\tAvaliacao %d (%f) = %f\n", i, ind[i].avaliacao, fit[i]); // essa funcao foi feita para limitar em que ponto se quer chegar a populacao, limitar sua avaliacao do sistema;
    }
}

void elitismo(float *fit, ind *ind){
    float maxfit = fit[1];
    int maxi = 1;
    for(int i = 1; i<TamPop; i++){  // seleciona o maior fit e seu indice
        if(fit[i]>maxfit){
            maxfit = fit[i];
            maxi = i;   
        }
    }
    for(int i = 0;i<TamPop;i++){
        if(i==maxi)                     // nao deixa perder o melhor individuo
            continue;
        
        // crossover
        ind[i].avaliacao = (ind[i].avaliacao + ind[maxi].avaliacao)/2.0;
    }
}