#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoesEvolucao.h"

int gen = 0;

void initpop(ind *ind, int labirinto[LINHAS][COLUNAS]){
    for(int i = 0; i<TamPop; i++){  // preenche o vetor com a populacao
        ind[i].pontos = 0; 
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
        x = ind[i].pontos;
        y = x;
        moveIndividuo(labirinto, &ind[i]);
        printf("AQUI CARALHO %d, %d\n\n", ind[i].posi, ind[i].posj);
        fit[i] = y;
        printf("\tAvaliacao %d (%f) = %f\n", i, ind[i].pontos, fit[i]); // essa funcao foi feita para limitar em que ponto se quer chegar a populacao, limitar sua avaliacao do sistema;
    }
}

void exterminio(ind *ind){
    int minfit1 = 0, minfit2 = 1;

    if(ind[0].pontos > ind[1].pontos){
        minfit1 = 1;
        minfit2 = 0;
    }

    for(int i = 2; i < TamPop - Exterminio; i++){
        if(ind[i].pontos < ind[minfit2].pontos){
            if(ind[i].pontos < ind[minfit1].pontos){
                minfit2 = minfit1;
                minfit1 = i;
            }
            else 
                minfit2 = i;
        }
    }

    for(int i = min1; i < min2; i++)
        ind[i] = ind[i+1];
    for(int i = min2; i < TamPop - 1; i++)
        ind[i-1] = ind[i+1];
}

int* elitismo(ind *ind){
    int maxfit1 = 0, maxfit2 = 1;

    if(ind[0].pontos < ind[1].pontos){
        maxfit1 = 1;
        maxfit2 = 0;
    }

    for(int i = 2; i < TamPop - Exterminio; i++){
        if(ind[i].pontos > ind[maxfit2].pontos){
            if(ind[i].pontos > ind[maxfit1].pontos){
                maxfit2 = maxfit1;
                maxfit1 = i;
            }
            else 
                maxfit2 = i;
        }
    }

    int maxfit[2] = {maxfit1, maxfit2};

    return maxfit;
}

void crossover(ind ind, ind* novaPop, int maxfit1, int maxfit2){
    int tamNovaPop = 2;

    for(int i = 0; (i < TamPop - Exterminio) && (tamNovaPop < TamPop); i++){
        if(i == maxfit1 || i == maxfit2)
            continue;
        
        ind novoInd1 = ind[maxfit1];
        ind novoInd2 = ind[i];
        for(int j = TAM/2; j < TAM; j++){
            novoInd1.caminho[j] = ind[i].caminho[j];
            novoInd2.caminho[j] = ind[maxfit2].caminho[j];
        }
        novaPop[tamNovaPop++] = novoInd1;
        novaPop[tamNovaPop++] = novoInd2;
    }
}

// void mutacao(ind *novaPop){
//     for(int i = 2; i < TamPop; i++){
//         int qntMutacoes = rand() % (TAM/4);

//         for(int j = 0; j < qntMutacoes; j++){
//             int movimento = rand() % 4;
//             int posicao = rand() % TAM;

//             novaPop[i].caminho[posicao] = movimento;
//         }
//     }
// }

ind* cruzamento(ind *ind){
    exterminio(ind);
    int maxfit[2] = elitismo(ind);

    ind novaPop[TamPop];
    novaPop[0] = ind[maxfit[0]];
    novaPop[1] = ind[maxfit[1]];

    crossover();
    // mutacao(&novaPop);

    return &novaPop;
}