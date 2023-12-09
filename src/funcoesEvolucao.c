#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoesEvolucao.h"

int gen = 0;

void initpop(ind *ind){
    for(int i = 1; i<=TamPop; i++){
        ind[i].avaliacao = 0; // preenche o vetor com a populacao
        //printf("ind[%d] = %f\n", i, ind[i]); //mostrar individuos gerados
    }
}

void movimentaIndividuo(ind ind, float *y){
    int movimento;
    movimento = (int)(rand() % 4);
    for(int i = 0; i < 10; i++){
        if(movimento == 0){
            ind.posi = ind.posi++;
            *y = *y + 10;
        }else if(movimento == 1){
            ind.posj = ind.posj++;
            *y = *y + 10;
        }else if(movimento == 2){
            ind.posj = ind.posj++;
            *y = *y - 10;
        }else if(movimento == 3){
            ind.posj = ind.posj--;
            *y = *y - 10;
        }
    }
}

void avalia(float *fit, ind *ind){
    float x;
    float y;
    printf("Generacao: %d\n", gen); // printa em qual geracao esta
    gen++;
    for(int i = 1; i<=TamPop; i++){
        x = ind[i].avaliacao;
        y = x;
        if(x == 0)
            movimentaIndividuo(ind[i], &y);
        fit[i] = y;
        printf("\tAvaliacao %d (%f) = %f\n", i, ind[i].avaliacao, fit[i]); // essa funcao foi feita para limitar em que ponto se quer chegar a populacao, limitar sua avaliacao do sistema;
    }
}

void elitismo(float *fit, ind *ind){
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
        ind[i].avaliacao = (ind[i].avaliacao + ind[maxi].avaliacao)/2.0;
    }
}