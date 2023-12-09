#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoesEvolucao.h"

int gen = 0;

void initpop(float *ind){
    for(int i = 1; i<=TamPop; i++){
        ind[i] = (float)(rand() % maxx); // preenche o vetor com a populacao
        //printf("ind[%d] = %f\n", i, ind[i]); //mostrar individuos gerados
    }
}

void avalia(float *fit, float *ind){
    float x;
    printf("Generation: %d\n", gen); // printa em qual geracao esta
    gen++;
    for(int i = 1; i<=TamPop; i++){
        x = ind[i];
        float y = x;
        if(x>500)
            y = 1000 - x;
        fit[i] = y;
        printf("\tFitness %d (%f) = %f\n", i, ind[i], fit[i]); // essa funcao foi feita para limitar em que ponto se quer chegar a populacao, limitar sua avaliacao do sistema;
    }
}

void elitismo(float *fit, float *ind){
    float maxfit = fit[1];
    int maxi = 1;
    for(int i = 2; i<=TamPop; i++){  // seleciona o maior fit e seu indice
        if(fit[i]>maxfit){
            maxfit = fit[i];
            maxi = i;   
        }
    }
    for(int i = 1;i<=TamPop;i++){
        if(i==maxi)                     // nao deixa perder o melhor individuo
            continue;
        
        // crossover
        ind[i] = (ind[i] + ind[maxi])/2.0;
    }
}