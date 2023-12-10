#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoesEvolucao.h"

int gen = 0;

void initpop(ind *ind, int labirinto[LINHAS][COLUNAS]){
    for(int i = 0; i < TamPop; i++){  // preenche o vetor com a populacao
        ind[i].pontos = 0; 
        ind[i].posi = LINHAS - 2;
        ind[i].posj = COLUNAS - 2;
        //printf("ind[%d] = %f\n", i, ind[i]); //mostrar individuos gerados
    }
}

void avalia(float *fit, ind *ind, int labirinto[LINHAS][COLUNAS]){
    printf("Generacao: %d\n", gen); // printa em qual geracao esta
    int gereacaoRandomica = 0;
    gen++;
    for(int i = 0; i < TamPop; i++){
        if(gereacaoRandomica == 0)
            moveIndividuoInicial(labirinto, &ind[i]);
        else if(gereacaoRandomica == 1)
            moveIndividuo(labirinto, &ind[i]);
        for(int j = 0; j < TAM; j++){
            if(ind[i].caminho[j] == 1 || ind[i].caminho[j] == 2)
                ind[i].pontos += 10;
            else if(ind[i].caminho[j] == 0 || ind[i].caminho[j] == 3)
                ind[i].pontos -= 10;
            else if(ind[i].caminho[j] == 4)
                ind[i].pontos -= 5;
            printf("%d, ", ind[i].caminho[j]);
        }
        if(ind[i].posi - 1 < 4)
            ind[i].pontos += 60;
        if(ind[i].posj - 1 < 9)
            ind[i].pontos += 40;
        printf("SOMA DE PONTOS: %f\n", ind[i].pontos);
    }
    gereacaoRandomica = 1;
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
        ind[i].pontos = (ind[i].pontos + ind[maxi].pontos)/2.0;
    }
}